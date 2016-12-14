					;-*- mode: lisp; coding: cp1251;-*-

(defun extract-function (filename)
    (declare (optimize (safety 3) (space 3) (debug 3) (speed 1)))
    (let ((in-stream (open filename :direction :input))
	  (out-stream (open "c:/Users/cglooschenko/lisp/project/aiku-system/out.txt" :direction :output :if-exists :overwrite :if-does-not-exist :create))
	  in-line func-name)
	(labels ((convert-case (prev-char in-list &aux (cur-char (car in-list)) (ap-char (char-downcase prev-char)))
		     (append (cond ((or (not cur-char)
					(char= #\- (car (setq in-list (convert-case cur-char (cdr in-list)))))
					(apply #'= (setq prev-char
							 (mapcar #'(lambda (in) (cdr (assoc (upper-case-p in) '((nil . 0) (t . 1)))))
								 (list prev-char cur-char)))))
				    (list ap-char))
				   ((apply #'> prev-char) (list #\- ap-char))
				   ((apply #'< prev-char) (list ap-char #\-)))
			     in-list))
		 (translate-name (in-name)
		     (concatenate 'string (if (char/= #\- (car (setq in-name (convert-case (car (setq in-name (coerce in-name 'list)))
											   (cdr in-name)))))
					      in-name
					      (cdr in-name))))
		 (translate-parameter-list (in-list)
		     (concatenate 'string
				  (string #\newline) "("
				  (translate-name (car (setq in-list (nreverse in-list))))
				  " "
				  (or (cdr (assoc (read-from-string (setq in-list (or (cadr in-list) (car in-list)))) +convert-data-types+))
				      (concatenate 'string "(:pointer (:struct " (string-downcase in-list) "))"))
				  ")"))
		 (remove-bad-char (in-list &aux (in-char (car in-list)))
		     (and (not (member in-char '(#\, nil #\return #\;)))
			  (append (and (not (member in-char '(#\) #\( #\tab #\* #\; #\{ #\}))) (list in-char))
				  (if (eq #\space (car (setq in-list (remove-bad-char (cdr in-list)))))
				      (append '(#\" #\") (cdr in-list))
				      in-list))))
		 (convert-line (in-line)
		     (remove-if  #'(lambda (in) (or (zerop (length in))
						    (char= #\space (elt in 0))
						    (and (< 1 (length in))(string= "__" (subseq in 0 2)))))
				 (read-from-string (concatenate 'string
								(append '(#\( #\")
									(remove-bad-char (coerce in-line 'list))
									'(#\" #\)))))))
		 (extract-string-fun (in-line)
	    	     (if (find #\; in-line)
			 (list (convert-line in-line))
			 (cons (convert-line in-line) (extract-string-fun (read-line in-stream nil)))))
		 (extract-string-slot (in-line)
	    	     (and (not (find #\} in-line))
			  (cons (convert-line in-line) (extract-string-slot (read-line in-stream nil))))))
	    (loop while (setq in-line (read-line in-stream nil))
		  do (if (and (every #'char= "WINBASEAPI" in-line)
			      (char/= #\A
				      (elt (setq func-name (caaddr (setq in-line (remove nil (extract-string-fun (read-line in-stream nil))))))
					   (1- (length func-name)))))
			 (write-line (concatenate 'string
						  (string #\newline)
						  "(cffi:defcfun ("
						  (string-right-trim "-w" (translate-name func-name))
						  " \"" func-name "\" :convention :stdcall :library \"user32.dll\")"
						  (string #\newline)
						  (or (cdr (assoc (setq func-name (read-from-string (caar in-line))) +convert-data-types+))
						      (concatenate 'string ":"(symbol-name func-name)))
						  (apply #'concatenate (cons 'string (mapcar #'translate-parameter-list (cdddr in-line))))
						  ")")
				     out-stream)
			 (if (and (>= (length in-line) (length "typedef struct tag"))
				  (every #'char= "typedef struct tag" in-line))
			     (write-line (concatenate 'string
						      (string #\newline)
						      "(cffi:defcstruct "
						      (string-downcase (string-right-trim '(#\return #\{ #\space)
											  (subseq in-line (length "typedef struct tag"))))
						      (apply #'concatenate (cons 'string (mapcar #'translate-parameter-list
												 (remove nil (extract-string-slot (read-line in-stream nil))))))
						      ")")
				        out-stream)))))
	(mapcar #'close (list in-stream out-stream))))
;;
(extract-function "c:/Users/cglooschenko/lisp/project/aiku-system/in.txt")
