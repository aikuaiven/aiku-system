;-*- mode: lisp; encoding: cp1251; -*-

(in-package :common-lisp)
(ql:quickload :cffi)
(defpackage :aiku (:use :common-lisp :cffi))
(in-package :aiku)
(defparameter *package-api-path*
  "~/project/aiku-system/"
  "package path winAPI")

(mapcar 'set '(*print-case* *print-circle*) '(:downcase t))

(cffi:defctype :handle :uint64)

(mapcar (function (lambda (file-name) (load (concatenate 'string *package-api-path* file-name))))
	'("win-user.lisp" "win-base.lisp" "debug-function.lisp" "compatibility-cffi-function.lisp"))

