(defvar lis1) (defvar lis2) (defvar flag) (defvar cnt)
(defvar tmplis) (defvar cpr1) (defvar cpr2)
(setq lis1 '(nil))
(setq lis2 '(nil))

(with-open-file (in1 "file1.txt"
				 :direction :input
				 :if-does-not-exist :create)
	(loop for line = (read-line in1 nil)
	 while line do
	 	(push line lis1)))
;(push nil lis1)
(setq lis1 (reverse lis1))
(setq lis1 (cdr lis1))

;(dolist (x lis1) (print x))

(with-open-file (in2 "file2.txt"
				 :direction :input
				 :if-does-not-exist :create)
	(loop for line = (read-line in2 nil)
	 while line do
	 	(push line lis2)))
;(push nil lis2)
(setq lis2 (reverse lis2))
(setq lis2 (cdr lis2))



;(with-open-file (out "out.txt" 
;				 :direction :output 
;				 :if-exists :supersede 
;				 :if-does-not-exist :create))
(loop for x from 1 to (length lis1) do
 	(setq flag 0)
	(setq cnt 0)
	(setq tmplis lis2)
 	(setq cpr1 (car lis1))
	(loop for y from 1 to (length lis2) do
	 	(setq cpr2 (car tmplis))
	 	(when (string= cpr1 cpr2) (setq flag 1) (return))
		(setq tmplis (cdr tmplis))
		(setq cnt (+ cnt 1)))
	(when (eq flag 0)
		(format t "~c[31m-~a~c[0m~%" #\ESC cpr1 #\ESC)
		(setq lis1 (cdr lis1)))
	(when (not (eq flag 0))
		(setq lis1 (cdr lis1))
		(loop for z from 1 to cnt do
		(format t "~c[32m+~a~c[0m~%" #\ESC (car lis2) #\ESC)
		(setq lis2 (cdr lis2)))
		(setq lis2 (cdr lis2))
		(format t " ~a~%" cpr2)))

(loop for x from 1 to (length lis2) do
 	(format t "~c[32m+~a~c[0m~%" #\ESC (car lis2) #\ESC)
	(setq lis2 (cdr lis2)))


;	(format t "~c[32mabc~c[0m~%" #\ESC #\ESC)
;	(dolist (xx lis1) (format out "~a~%" xx))

;	(loop for x from 1 to 5 do (format t "~d~%" x)))


;		 (string-equal x y)

