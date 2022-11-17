# Leetcode

리트코드 문풀(cpp / python)

00002_Add_Two_Numbers.py
-

00005_Longest_Palindromic_Substring.cpp   
-
n 문자열에서 가장 긴 대치 문자열 반환
n = 1000 -> O(n^2)   
1 : vec left, right, len   
2 : 같은 문자로 이루어진 문자열을 찾아 vec에 좌우 인덱스와 길이 저장. ex aaa   
3 : 좌우가 같으며 중앙이 다른 길이가 3인 문자열을 찾아 마찬가지로 vec에 저장. ex aba   
4 : 지금까지 모은 벡터를 좌우로 확장시켜가며 조건 검사   
🎯 aaa, aba를 따로 모은다는 발상

00015._3Sum.py 
-

00022_Generate_Parentheses.cpp  
- 
'(' 와 ')'를 n번 써서 모든 닫힌 괄호 조합 만들기   
n = 8   
1 : 중복을 제거할 vector<uset> subMaps생성   
-> subMaps[i]에 i쌍으로 구성된 조합이 포함됨   
2 : for i <= n, i쌍으로 구성된 조합을 생성하고 subMaps[i]에 삽입   
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
1 : i까지 최소 점프 수를 나타나는 vec jumps 선언    
2 : for i < n, jumps[i]를 작성    
3 : for i+1 < j < i+x, jumps[j]를 조사    
-> 만약 jumps[j]가 jumps[i]+1보다 작다면 jumps[i]+1로 대체     
--> jumps[i]에서 점프 한번 내에 도달할 수 있다면     

00055_Jump_Game.cpp
-
길이 n 배열 nums에서 배열의 값 x만큼 다음 칸으로 점프 가능 할 때, 마지막에 닿을 수 있는가?   
n = 10e4, x = 10e5    
점프하여 중간에 끊김이 없어야 함   
1 : 최대 도달 idx를 나타내는 reach 선언    
2 : for i < n, reach가 idx보다 작으면 끊긴것. false    
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
1 : left=0, right=mn, mid=(right+left)/2   
2 : if target < x, right=mid    
-> else left=mid+1   
🎯 left는 서치 idx 포함, right는 서치 idx 벗어남     
🎯 mid는 나누기가 반복되면 왼쪽으로 치우침   
🎯 따라서 치우침을 보정하기 위해 right=mid or left=mid+1   

00092_Reverse_Linked_List_II.py   
-

00097_Interleaving_String.cpp   
-
str s1 s2를 잘 섞어 s3을 만들 수 있는가?     
1 : 2차원 (s1_sz+1)*(s2_sz+1) dp 테이블 생성    
-> 세로 : s1 방향, 가로 : s2 방향    
2 : 0행, 0열 정의   
3 : s1이 추가되어 s3가 되거나, s2가 추가되어 s3가 된다면 true   
🎯 입력보다 1 큰 각 tb 차원    
🎯 s1 혹은 s2 하나로만 s3가 이루어져도 true     

00743_Network_Delay_Time.cpp   
-
그래프 모든 n노드 방문시 소요되는 최소 cost 반환   
그래프 : weighted, 단방향성   
노드 : 유니크함   
n = 100   
1 : 그래프를 저장할 자료구조 tb 생성   
-> tb : vec<vec<weight, next>>    
2 : 우선순위 큐를 이용하여 순회   
-> 방문은 벡터로 모여짐   
--> 이미 방문하였다면 모여지지 않음   
---> 다른 문제처럼 다음 방문을 찾을 때 기 방문을 검사하면 안 됨.   
----> 지금 케이스는 어떻게 weight가 결정될 지 모르는 상황   
-----> 즉, 같은 노드에 대해, 나중에 모아진 것이 앞서 모아진 것 보다 weight가 낮을(좋을) 수 있음   
------> 따라서 이미 방문 했을 때 결정   
-> 우선순위 큐 : (누적 weight, 다음 방문)   
3 : 방문 벡터를 이용해 다음 방문을 찾고 다음 방문을 우선순위 큐에 저장   
-> weight는 누적해서 다음 방문으로 전파함   
--> 그렇지 않으면 이전 노드 - weight 테이블을 만드는 등 복잡한 작업이 수반 될 수 있음   
🎯 우선순위 큐를 이용한 탐색    
🎯 순서 결정이 모호하면 방문시 visited 결정    
🎯 tb의 가장 외각은 vec -> 노드가 주어지고 임의 접근할 것이기 때문   
🎯 tb의 inner는 vec -> 어차피 다음 방문 지역을 다 우선순위 큐에 넣을 것이므로   

945_Minimum_Increment_to_Make_Array_Unique.cpp   
-
n배열이 주어질 때 원소의 값 x를 바꾸어, 중복없애기 위한 최소 코스트는?   
코스트 : x를 1 바꿀 때 마다 1   
n, x = 10e5   
1 : 존재하는 원소를 기록   
2 : 기록을 바탕으로, 중복되는 원소를 중복을 포함하여 deq yet으로 모음     
3 : deq을 정렬     
4 : 기록을 바탕으로, 배열에 존재하지 않는 원소를 나타내는 deq remains생성    
-> 오름차순임    
5 : 두 덱을 앞에서부터 비교하여 제거해 나가고, 코스트를 계산    
🎯 x가 모두 10e5일 수 있으므로 remains의 최댓값은 2*10e5 가량일 수 있음    
🎯 deq과 정렬을 이용해 set 등을 사용하지 않고 풀어냄    
혹은 다른 방법으로    
1 : x에 대한 히스토그램을 만듦    
2 : 히스토그램을 왼쪽부터 순회, 히스토그램 높이가 1이 되게끔하며 오른쪽으로 원소를 넘기며 코스트 계산    
-> 높이가 1은 중복이 없음을 의미    
🎯 히스토그램으로 생각해도 최종 코스트가 같다는 발상    
