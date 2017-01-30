執行環境：
	使用putty連線至老師給的位址執行(140.116.245.27)

編譯：
	g++ -o Hw4 Hw4.cpp -lpthread
	有Makefile

程式流程：
	執行程式時會請使用者輸入number of threads (by scanf)
	創建好threads之後用mutex_lock和main thread做溝通
	各個thread分工處理一部份smooth存放到BMPSAVEDATA
	都處理好後main thread把BMPSAVEDATA和BMPDATA做交換
	才讓各thread做下一次smooth
