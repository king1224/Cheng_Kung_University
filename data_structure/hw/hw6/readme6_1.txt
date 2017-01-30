開發平台(Development Platform):		Win10

使用開發環境(Development environment):	DEV-C++ 5.8.3

程式功能(Program Functions): 		
Sollin’s Algorithm 實作


程式設計(Program design):		
in main
19-26　 初始化
30-36　 讀進矩陣
44-59　 一開始每個點自成一棵tree，取每一列找最小值
　　　　即為對每個tree找最小權重邊
64-73 　針對中edge誰和誰有邊，判斷哪些同棵樹，用node陣列存
78　　　先檢查是否已經全部同一棵樹了


79　　　當還沒全部同棵樹，持續做以下動作
81　　　從第一棵樹檢查到最後一棵樹，持續做以下動作
85-99 　對其中一棵樹中的每個node去找相鄰邊，
　　　　找到後比對是否為最小，最小=>存起來
100-109 若有找到有效的最小臨邊，將其中一棵tree node完全換成另一棵
110-111 檢查是否已經完全同一棵tree了


116-132 持續掃整個array，每次從最小的邊開始印出，印出後初始化edge2



in sametree　將各棵樹存進node 陣列裡面
從指定的edge2的某一列開始找
並將這一列的node視為編號tree_index的樹
找這列是否連接其他node
若有，呼叫被連接的那一列sametree，將那一列視為編號tree_index的樹
繼續尋找有沒有串在一起的