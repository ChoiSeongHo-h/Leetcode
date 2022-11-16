# Leetcode

리트코드 문풀(cpp / python)

00002_Add_Two_Numbers.py
-

00005_Longest_Palindromic_Substring.cpp   
-
n 문자열에서 가장 긴 대치 문자열 반환
n = 1000 -> O(n^2)   
0 : vec left, right, len   
1 : 같은 문자로 이루어진 문자열을 찾아 vec에 좌우 인덱스와 길이 저장. ex aaa   
2 : 좌우가 같으며 중앙이 다른 길이가 3인 문자열을 찾아 마찬가지로 vec에 저장. ex aba   
3 : 지금까지 모은 벡터를 좌우로 확장시켜가며 조건 검사   
🎯 aaa, aba를 따로 모은다는 발상

00015._3Sum.py 
-

00022_Generate_Parentheses.cpp  
- 
'(' 와 ')'를 n번 써서 모든 닫힌 괄호 조합 만들기   
n = 8   
0 : 중복을 제거할 vector<uset> subMaps생성   
-> subMaps[i]에 i쌍으로 구성된 조합이 포함됨   
1 : for i <= n, i쌍으로 구성된 조합을 생성하고 subMaps[i]에 삽입   
생성 : combine하여 생성, generate하여 생성   
combine : a+b=i인 subMaps[a]와 subMaps[b]의 원소를 섞어 생성   
generate : subMaps[i-1]의 모든 원소들의 왼쪽에 '(', 오른쪽에 ')'를 붙혀 감싸줌   
🎯 상위집합은 하위 집합으로 구성 가능하며 combine과 generate로 나뉠 수 있다는 발상   

00024_Swap_Nodes_in_Pairs.py
-

00042_Trapping_Rain_Water.py
-

00045_Jump_Game_II.cpp   
-
길이 n 배열 nums에서 배열의 값 x만큼 다음 칸으로 점프 가능 할 때, 마지막에 닿을 수 있는 최소 점프 수는?   
n = 10e4, x = 10e3 -> O(nj)   
0 : i까지 최소 점프 수를 나타나는 vec jumps 선언    
1 : for i < n, jumps[i]를 작성    
2 : for i+1 < j < i+x, jumps[j]를 조사    
-> 만약 jumps[j]가 jumps[i]+1보다 작다면 jumps[i]+1로 대체     
--> jumps[i]에서 점프 한번 내에 도달할 수 있다면     

00055_Jump_Game.cpp
-
길이 n 배열 nums에서 배열의 값 x만큼 다음 칸으로 점프 가능 할 때, 마지막에 닿을 수 있는가?   
n = 10e4, x = 10e5    
점프하여 중간에 끊김이 없어야 함   
0 : 최대 도달 idx를 나타내는 reach 선언    
1 : for i < n, reach가 idx보다 작으면 끊긴것. false    
-> 그렇지 않으면 reach = max(reach, i+x)     

00062_Unique_Paths.cpp
-
m*n 그리드에서 오른쪽 아래로 가는 unique pathes 수를 반환    
m, n = 100   
1. for tale[i][j] = table[i-1][j]+table[i][j-1]   

00074_Search_a_2D_Matrix.cpp
-
m*n 그리드에서 targe을 찾으려 함    
그리드 : 좌우, 상하 방향으로 값 x가 정렬됨    
-10e4 < x, target < 10e4    
m, n = 100    
그리드를 1d로 보고 이진탐색   
0 : left=0, right=mn, mid=(right+left)/2   
1 : if target < x, right=mid    
-> else left=mid+1   
🎯 left는 서치 idx 포함, right는 서치 idx 벗어남     
🎯 mid는 나누기가 반복되면 왼쪽으로 치우침   
🎯 따라서 치우침을 보정하기 위해 right=mid or left=mid+1   

00743_Network_Delay_Time.cpp   
-
그래프 모든 n노드 방문시 소요되는 최소 cost 반환   
그래프 : weighted, 단방향성   
노드 : 유니크함   
n = 100   
0 : 그래프를 저장할 자료구조 tb 생성   
-> tb : vec<vec<weight, next>>    
1 : 우선순위 큐를 이용하여 순회   
-> 방문은 벡터로 모여짐   
--> 이미 방문하였다면 모여지지 않음   
---> 다른 문제처럼 다음 방문을 찾을 때 기 방문을 검사하면 안 됨.   
----> 지금 케이스는 어떻게 weight가 결정될 지 모르는 상황   
-----> 즉, 같은 노드에 대해, 나중에 모아진 것이 앞서 모아진 것 보다 weight가 낮을(좋을) 수 있음   
------> 따라서 이미 방문 했을 때 결정   
-> 우선순위 큐 : (누적 weight, 다음 방문)   
2 : 방문 벡터를 이용해 다음 방문을 찾고 다음 방문을 우선순위 큐에 저장   
-> weight는 누적해서 다음 방문으로 전파함   
--> 그렇지 않으면 이전 노드 - weight 테이블을 만드는 등 복잡한 작업이 수반 될 수 있음   
🎯 우선순위 큐를 이용한 탐색, 방문시 visited 결정   
🎯 tb의 가장 외각은 vec -> 노드가 주어지고 임의 접근할 것이기 때문   
🎯 tb의 inner는 vec -> 어차피 다음 방문 지역을 다 우선순위 큐에 넣을 것이므로   
