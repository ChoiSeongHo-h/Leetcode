# Leetcode

리트코드 문풀(cpp / python)

00002_Add_Two_Numbers.py
-
https://leetcode.com/problems/add-two-numbers/   

00005_Longest_Palindromic_Substring.cpp   
-
https://leetcode.com/problems/longest-palindromic-substring/   
n 문자열에서 가장 긴 대치 문자열 반환   
n = 1000 -> O(n^2)   
1 : vec left, right, len   
2 : 같은 문자로 이루어진 문자열을 찾아 vec에 좌우 인덱스와 길이 저장. ex aaa   
3 : 좌우가 같으며 중앙이 다른 길이가 3인 문자열을 찾아 마찬가지로 vec에 저장. ex aba   
4 : 지금까지 모은 벡터를 좌우로 확장시켜가며 조건 검사   
🎯 aaa, aba를 따로 모은다는 발상

00015._3Sum.py 
-
https://leetcode.com/problems/3sum/   

00022_Generate_Parentheses.cpp  
- 
https://leetcode.com/problems/generate-parentheses/   
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
https://leetcode.com/problems/swap-nodes-in-pairs/   

00042_Trapping_Rain_Water.py
-
https://leetcode.com/problems/trapping-rain-water/   

00045_Jump_Game_II.cpp   
-
https://leetcode.com/problems/jump-game-ii/   
길이 n 배열 nums에서 배열의 값 x만큼 다음 칸으로 점프 가능 할 때, 마지막에 도달 가능 한 최소 점프 수는?   
n = 10e4, x = 10e3 -> O(nj)   
1 : i까지 최소 점프 수를 나타나는 vec jumps 선언    
2 : for i < n, jumps[i]를 작성    
2-1 : for i+1 < j < i+x, jumps[j]를 조사    
-> jumps[j] = min(jumps[j], jumps[i]+1)     
--> jumps[i]에서 점프 한번 내에 도달 vs 기존 값     

00053_Maximum_Subarray.cpp   
-   
n 배열 nums에서 부분합이 최대가 되는 subarray의 합을 구하여라   
n = 10e5   
카데인 알고리즘 사용   
1 : for nums[i] : nums에 대해 다음을 반복   
1-1 : 로컬미니마 = max(이전 로컬미니마 + nums[i], nums[i])   
1-2 : 글로벌미니마 = max(로컬미니마, 글로벌미니마)   
🎯 새로 비교할 단일합 nums[i]와 이전단계 최대값+nums[i]와만 비교하면 됨   
-> nums[0] ~ nums[i]의 최대 부분합    
🎯 잘못된 접근 방법 1 : l2r, r2l 합 배열 구하여 각 배열에서 가장 큰 음수를 가지는 idx 사이를 합하자   
-> nums = [-2,1,-3,4,-1,2,1,-5,4]     
-> l2r  = [-2,-1,-4,0,-1,1,2,-3,1]     
-> r2l  = [1,3,2,5,1,2,0,-1,4]       
--> l2r -4를 나타내는 idx 2, r2l -1을 나타내는 idx 7 사이를 합하자     
---> 양수가 대부분이면 작동하나, 음수에 지배당하면 잘 동작하지 않음   
🎯 잘못된 접근 방법 2 : nums의 음수간 구간을 정하여 합하여 비교해 보자   
-> 곱에서는 잘 동작할 수 있으나, 주어진 문제는 합의 문제   

00055_Jump_Game.cpp
-
https://leetcode.com/problems/jump-game/   
길이 n 배열 nums에서 배열의 값 x만큼 다음 칸으로 점프 가능 할 때, 마지막에 닿을 수 있는가?   
n = 10e4, x = 10e5    
점프하여 중간에 끊김이 없어야 함   
1 : 최대 도달 idx를 나타내는 reach 선언    
2 : for i < n, reach가 idx보다 작으면 끊긴것. false    
-> 그렇지 않으면 reach = max(reach, i+x)     

00062_Unique_Paths.cpp
-
https://leetcode.com/problems/unique-paths/   
m*n 그리드에서 오른쪽 아래로 가는 unique pathes 수를 반환    
m, n = 100   
1 : for tale[i][j] = table[i-1][j]+table[i][j-1]   

00074_Search_a_2D_Matrix.cpp
-
https://leetcode.com/problems/search-a-2d-matrix/   
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
https://leetcode.com/problems/reverse-linked-list-ii/   

00097_Interleaving_String.cpp   
-
https://leetcode.com/problems/interleaving-string/   
str s1 s2를 잘 섞어 s3을 만들 수 있는가?     
len(s1), len(s2) = 100
1 : 2차원 (s1_sz+1)*(s2_sz+1) dp 테이블 생성    
-> 세로 : s1 방향, 가로 : s2 방향    
2 : 0행, 0열 정의   
3 : s1이 추가되어 s3가 되거나, s2가 추가되어 s3가 된다면 true   
🎯 입력보다 1 큰 각 tb 차원    
🎯 s1 혹은 s2 하나로만 s3가 이루어져도 true     

00098_Validate_Binary_Search_Tree.cpp    
-    
https://leetcode.com/problems/validate-binary-search-tree/   
n노드 이진 탐색 트리가 맞나 검사    
n = 10e4    
각 노드 값은 하항과 상한을 가짐    
1 : 완전 탐색으로 상한과 하한을 넘겨주며 순회    
2 : 왼쪽 노드의 값이 자신의 값보다 크거나, 자기 하한의 값이 왼쪽 노드 값보다 크거나 같으면 ret false    
2-1 : 왼쪽 노드를 탐색, 이 때 하한은 그대로, 상한은 자신의 값    
3 : 오른쪽 노드의 값이 자신의 값보다 작거나, 오른쪽 노드 값이 자기 상한의 값보다 크거나 같으면 ret false    
3-1 : 오른쪽 노드를 탐색, 이 때 상한은 그대로, 하한은 자신의 값    
🎯 상한과 하한을 넘겨주며 순회한다는 발상    
🎯 자기 하한의 값이 왼쪽 노드 값보다 크거나 같으면 안 됨    
🎯 오른쪽 노드 값이 자기 상한의 값보다 크거나 같으면 안 됨    

00107_Binary_Tree_Level_Order_Traversal_II.cpp   
-
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/   
이진트리 값을 depth-wise로 반환   
1 : 이진트리를 depth-wise로 순회    
2 : depth-wise 생성된 vec에 값 삽입, depth가 끝나면 vec 요소를 옮겨담음    

00117_Populating Next_Right_Pointers_in_Each_Node_II.cpp    
-
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/   
이진트리를 depth-wise 순회하며 왼쪽노드의 next가 오른쪽 노드를 포인팅하게 함    
1 : 이진트리를 depth-wise 순회    
2 : 전역으로 이전 노드를 포인팅하는 포인터 선언   
3 : 만약 depth-wise 첫 노드가 아니라면 이전 노드의 next가 현 노드를 가리키게 함   

00134_Gas Station.cpp   
-
https://leetcode.com/problems/gas-station/   
n vec gas, cost가 주어짐, 각 i에서 충전량, 소모량을 나타냄, 어떤 i에서 시작해야 주유소를 circular 순회할 수 있는가?    
n = 10e5 -> O(n)  
해는 유일    
1 : vec gap을 선언하여 순수 이득을 계산    
2 : net을 선언하여 1 cycle 순수 이득 net을 대입    
3 : n까지 순회하며 i에서 왼쪽 net netL, 오른쪽 net netR을 계산    
-> 초기에 0, net이며, gap[i]를 각각 빼고 더하여 구할 수 있음    
-> 해가 유일하므로 순 이득이 나는 곳은 하나임    
--> 이 곳은 netR이 최대화됨    
4 : netR이 최대화되는 곳을 찾음    
🎯 왼쪽 net, 오른쪽 net의 성질을 관찰    

00152_Maximum_Product_Subarray.cpp    
-
https://leetcode.com/problems/maximum-product-subarray/   
n길이 nums의 곱이 최대가 되는 연속적인 subarray의 곱을 구함      
n = 10e4 -> O(n)   
1 : 0 사이의 subarrays를 구함      
2 : 1의 subarrays[i]에 음수가 짝수개면 그대로 후보에 포함   
3 : 1의 subarrays[i]에 음수가 홀수개면 뒤의 음수를 하나 뺀 subarray와 앞의 음수를 하나 뺀 subarrays를 후보에 포함   
-> 3 -1 2 5 3 -1 -1   
--> (3 -1 2 5 3 -1) -1 and 3 -1 (2 5 3 -1 -1)   
-> 음수를 짝수개로 맞춘다는 뜻   
4 : 후보를 모두 곱하여 최종 결과 계산   
🎯 음수가 짝수개이기만 한다면, subarray가 길면 길수록 값이 커지거나 같다는 발상       

00153_Find_Minimum_in_Rotated_Sorted_Array.cpp   
-
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/   
전체를 circular shift하여 정렬할 수 있는 n길이 nums가 주어질 때 최소값을 log(n)으로 찾아라    
nums는 [4,5,6,7,0,1,2]와 같이 주어짐       
-> 0을 찾아야 함       
1 : 이진탐색하는 구간에서 좌측 값이 우측 값보다 커야 함       
-> ex : [0 1 2]       
-> 이 경우 좌측값을 ret       
--> 오직 이 경우에만 찾을 수 있음       
---> 이 경우가 아니라면 무조건 좌측 값이 우측보다 큼       
2 : 좌측 값이 중간 값보다 작다면 구간을 오른쪽으로 설정       
-> if(nums[left] < nums[mid]) then, left = mid+1       
3 : 좌측 값이 중간 값보다 크다면 구간을 왼쪽으로 설정       
-> else then, right = mid;       
🎯 이 경우 초기 right는 n-1을 가짐       
🎯 마찬가지로 나누기를 반복하며 구간이 왼쪽으로 치우쳐지므로 이를 보정       
🎯 구간 재설정 방법(2, 3)을 생각해 볼만 함       

00207_Course_Schedule.cpp    
-     
https://leetcode.com/problems/course-schedule/    
numCourses와 prerequisites[i] = [ai, bi]이 주어짐. b를 들어야 a를 들을 수 있을 때, numCourses만큼 수업을 들을 수 있는가?    
numCourses = 2000    
len(prerequisites) = 5000    
prerequisites에 사이클이 생기나 검사해야 함        
1 : vec<vec> prereqMap, uset heads를 구성    
-> prereqMap : prereqMap[a] = b1, b2, ...    
-> heads : b가 포함되면 제거하고, a를 삽입    
--> head는 이를 선행으로 하는 요소가 없음을 의미, head들은 선행을 요구    
---> 이를 map에 넣어 선행 요구사항을 검사할 것임    
2 : courseDepthStack을 구성    
-> courseDepthStack : 과목 코드와 dfs depth로 구성된 stack    
-> head들과 depth 1을 넣음        
2-1 : 지금까지 경로를 저장할 stack path를 선언    
2-2 : path와 연동되어 지금 패스 방문을 의미하는 vec visited 선언    
2-3 : visited와 유사하지만, 철회하지 않는 vec done 선언    
3 : courseDepthStack이 비지 않으면 다음을 수행    
3-1 : depth와 차원을 맞춰 path를 pop하고 visited를 false로 수정(철회)    
3-2 : 현재 course를 path와 visited, done에 등록    
3-3 : for nest : prereqMap[course]에 대해    
3-3-1 : visited라면(cycle 이라면) ret false    
3-3-2 : done이라면 이미 조사했으므로 continue    
3-3-3 : 그렇지 않다면 뎁스를 증가시켜 courseDepthStack에 삽입    
4 : ret true    
🎯 선행 조건 문제에서는 cycle이 생기면 fail    
-> depth와 path로 구성된 dfs로 조사    
🎯 done을 두어 visited와는 별개로, 이미 조사한 사이클에 대한 반복을 피함    

00209_Minimum_Size_Subarray_Sum.cpp    
-   
https://leetcode.com/problems/minimum-size-subarray-sum/   
nums의 subarray 합이 target보다 크거나 같게 되는 subarray 최소 길이는?    
1 <= target <= 10e9    
len(nums) = 10e5    
1 <= nums[i] <= 104    
1 : l2r 누적 합 배열 acc_sum을 구성    
-> len(acc_sum) = len(nums)+1    
-> 오름차순    
2 : len_lower = 2, len_upper = nums.size()로 초기화    
2-1 : 국지적으로 보장된 len을 저장 할 succ_lower를 선언    
3 : while(len_lower < len_upper)    
3-1 : len = (len_lower+len_upper)/2    
3-2 : for 0 < i < acc_sum.size()-len 까지 다음을 검사    
3-2-1 : consq_sum = acc_sum[i+len] - acc_sum[i]    
-> 구간 합을 의미    
3-2-2 : consq_sum >= target ? succ_lower 갱신    
3-2-3 : 갱신되었다면 len_upper = len, 그렇지 않다면 len_lower = len+1    
🎯 배열의 원소가 모두 양수이므로, 누적합은 오름차순    
🎯 우측을 탐색할 때 len_lower = len+1     
한편   
1 : 국소 최솟값 ans 선언   
2 : 투포인터를 움직여가며 구간합이 target 이상이라면, ans = min(ans, 구간합)    
🎯 모두 양수이므로 투포인터 사용 가능    

00300_Longest_Increasing_Subsequence.cpp
-
https://leetcode.com/problems/longest-increasing-subsequence/    
nums를 입력받을 때 가장 긴 증가하는 부분수열의 최대 길이는?    
-10e4 <= nums[i] <= 10e4    
LIS 알고리즘 사용     
1 : 길이를 반환할 vec arr 선언    
2 : for num : nums[i]에 대해 만약 arr.back()보다 num이 크다면 arr 뒤에 추가    
-> 갯수 증가    
3 : 그렇지 않다면 arr의 원소 중 num보다 간신히 크거나 같은 원소를 num으로 대체    
-> 갯수 유지    
-> 이를 이진탐색으로 찾을 수 있음    
🎯 lower_bound(arr.begin(), arr.end(), num) 정렬된 arr에 대해 num보다 크고 최솟값을 갖는 포인터를 반환    
🎯 한편 이진탐색을 직접 구현하기 위해서는, arr가 이미 정렬되었기 때문에 i-1, i+1 양쪽의 값을 비교할 필요 없음.   
-> 한 쪽만 비교하면 됨    

00337_House_Robber_III.cpp
-
https://leetcode.com/problems/house-robber-iii/   
n 노드를 가진 이진트리를 순회할 때 인접하지 않은 노드 값 합의 최대값은?     
n = 10e4 -> O(n)     
1 : 재귀적으로 순회     
-> 반복적으로 순회하기에는 당해 노드의 포함 / 비포함을 생각하기 쉽지 않음     
1-1 : 당해 노드를 사용하는 경우 순회     
-> 당해 노드 값 + 좌 노드 사용하지 않을 때의 값 + 우 노드 사용하지 않을 때의 값     
1-2 : 당해 노드를 사용하지 않는 경우 순회     
-> max(좌 노드 사용하지 않을 때의 값, 좌 노드 사용할 때의 값) +   
max(우 노드 사용하지 않을 때의 값, 우 노드 사용할 때의 값)     
1-3 : 위 둘을 비교하여 큰 것을 사용   
2 : 한편 단순 위처럼만 생각하면 시간 오버    
-> 한 노드를 방문하면 계속해서 use, not use 모두 계산하므로   
-> umap 사용   
--> 사용할 경우, 사용하지 않을 경우 둘 모두의 umap을 만듦   
---> 그렇지 않으면, 예컨데 use -> not use 순으로 한 노드를 검사할 때, 그 노드의 값은 use에 의해서만 결정됨   
🎯 순회문제를 재귀적, 반복적 양 면으로 바라보는 능력    
🎯 umap은 pt를 쿼리로 받을 수 있음        
🎯 순회시 O(n)이 아니라면 캐시를 고려    

00435_Non-overlapping_Intervals.cpp    
-    
https://leetcode.com/problems/non-overlapping-intervals/   
시간 [a, b]가 n개 주어질 때 최소 몇개 쌍을 제거해야 겹침이 없을까 ?    
n = 10e5    
-10e5 < a, b, <10e5    
O(nlog(n))    
1 : b기준 정렬, a는 중복 가능함에 유의    
2 : b에 대한 a를 순회, b를 저장    
2-1 : 순회하는 a가 저장된 b보다 커지면 b를 당해 b로 업데이트    
-> 겹치지 않음을 의미    
2-2 : 2-1이 아니라면 cnt++    
🎯 시간 겹침 문제에서는 뒷 시간을 기준으로 정렬을 시도    
🎯 앞 시간은 중복될 수 있음에 유의 -> vec   

00743_Network_Delay_Time.cpp   
-
https://leetcode.com/problems/network-delay-time/   
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

00881_Boats_to_Save_People.cpp
-
https://leetcode.com/problems/boats-to-save-people/   
사람의 각 무게 people이 주어짐, 2명씩, 무게 limit 한도로 실을 수 있는 배의 최소 필요량은?   
len(people) = 5*10e4   
limit = 3*10e4   
1 : 무게 히스토그램을 map으로 만듦   
2 : 다음을 반복   
2-1 : map back의 무게가 limit보다 크다면 back을 제거하고 개수를 카운트   
2-2 : map back의 무게가 limit보다 크지 않다면, front의 개수가 back의 개수보다 많은 경우, 적은 경우 같은 경우를 나누어 해결   
-> ex : front가 많다면 front의 개수를 back의 개수만큼 줄이고 back을 제거   
2-3 : 한편 front와 back이 같은 것을 나타낼 때 예외처리를 둠   
🎯 while(!histogram.empty())로 쉽게 루프 구성 가능   
🎯 위에서는 front, back을 사용했지만 실 구현에서는 begin, end -> end-- 사용에 주의, 대신 prev(end) 권장   
혹은   
1 : people을 정렬하고 투포인터 사용   
2 : 포인팅 원소의 무게가 limit을 초과하면 오른쪽 포인터만 왼쪽으로   
3 : 초과하지 않는다면 왼쪽 포인터를 오른쪽으로, 오른쪽 포인터를 왼쪽으로   
🎯 히스토그램이나 정렬로 모두 풀 수 있음   

00945_Minimum_Increment_to_Make_Array_Unique.cpp   
-
https://leetcode.com/problems/minimum-increment-to-make-array-unique/   
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

00994_Rotting_Oranges.cpp    
-    
https://leetcode.com/problems/rotting-oranges/    
m*n 2d 그리드에서 빈 공간, 신선한 오렌지, 썩은 오렌지가 주어짐. 부패는 1분마다 인접한 신선한 오렌지에게 전파됨. 전체 부패에 소요되는 시간은?    
m. n = 10    
1 : set freshs, rottens를 작성    
-> 신선한 오렌지와 유효한 썩은 오렌지의 좌표값    
-> 유효한 썩은 오렌지 : 주변에 부패를 전파시킬 수 있는, 갇혀있지 않은 오렌지    
-> set : 값으로 임의 접근이 필요, pair에 uset을 사용하지 못 함    
2 : rottens가 빌 때까지 다음을 반복 :    
2-1 : for rotten : rottens의 인접을 조사하여 부패할 신선한 오렌지 좌표를 candidates에 수집    
2-2 : candidates가 비지 않았다면 시간 증가    
2-3 : for candidate : candidates를 rottens에 추가하고 freshs에 추가    
2-4 : rottens에서 유효하지 못한 rotten 제거    
3 : freshs가 비어있다면 ret time    
3-1 : 그렇지 않다면 ret fail    
🎯 freshs, rottens를 운용, rottens가 빌 때까지 freshs가 비지 않는다면 실패    
🎯 임시 객체 candidates를 두어 모아두었다가 나중에 한번에 추가 / 삭제    
-> 혼란을 방지    
한편   
🎯 rottens를 set으로 두지 않고 queue로 운용     
-> 자동적으로 사용된 rotten은 제거됨    
--> 유효하지 않더라도 새로운 원소를 추가하지 못 하고 제거됨   
🎯 freshs를 set으로 두지 않고 단순 개수만 셈    
