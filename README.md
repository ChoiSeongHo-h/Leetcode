# Leetcode


![LeetCode Stats](https://leetcard.jacoblin.cool/csh8052g?theme=light&font=Arimo)   
리트코드 문풀(cpp / python)    

00015._3Sum.py 
-
https://leetcode.com/problems/3sum/   

00024_Swap_Nodes_in_Pairs.py
-
https://leetcode.com/problems/swap-nodes-in-pairs/   

00092_Reverse_Linked_List_II.py   
-
https://leetcode.com/problems/reverse-linked-list-ii/   

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
