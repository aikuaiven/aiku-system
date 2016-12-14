(in-package :aiku)

(defun make-cstruct (cstruct cslot-list &optional (pointer (foreign-alloc cstruct)))
    (declare (optimize (debug 3) (safety 3)))
    "make or edit structure, cslot ::= {slot-name slot-value slot-type::= type | encoding} => pointer"
    (mapcar (function (lambda (cslot)
		(if (stringp (cadr cslot))
		    (lisp-string-to-foreign (cadr cslot)
					    pointer
					    (1+ (* (foreign-type-size (foreign-slot-type cstruct (car cslot)))
						   (length (cadr cslot))))
					    :offset (foreign-slot-offset cstruct (car cslot))
					    :encoding (caddr cslot))
		    (setf (foreign-slot-value pointer cstruct (car cslot)) (cadr cslot)))))
	    cslot-list)
    pointer)

(defun memory-placing (list-param &optional (offset '(0)) &aux (type-param (caar list-param)) (value-param (cadar list-param)) (align-param (caddar list-param)))
    (declare (optimize (debug 3) (safety 3)))
    "placing to memory list-param => pointer"
    (if list-param
	(progn (rplacd offset
		       (memory-placing (cdr list-param)
				       (list (+ (car (if (zerop (logand (1- align-param) (car offset)))
						    offset
						    (rplaca offset (+ (car offset) (- align-param (logand (1- align-param) (car offset)))))))
						(if (listp type-param)
						    (car (rplaca type-param (* (1+ (length value-param)) (or (cdr (assoc (cdr type-param) '((:utf-16le . 2)))) 1))))		   
						    (foreign-type-size type-param))))))
	       (if (listp type-param)
		   (lisp-string-to-foreign value-param (cdr offset) (car type-param) :offset (car offset) :encoding (cdr type-param))
		   (setf (mem-ref (cdr offset) type-param (car offset)) value-param)))
        (rplacd offset (foreign-alloc :int8 :initial-element #x0 :count (car offset))))
    (cdr offset))
