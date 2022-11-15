# Leetcode

리트코드 문풀(cpp / python)

00002_Add_Two_Numbers.py

00005_Longest_Palindromic_Substring.cpp

😀 n 문자열에서 가장 긴 대치 문자열 반환
n = 1000 -> n^2
0. vec left, right, len
1. 같은 문자로 이루어진 문자열을 찾아 vec에 좌우 인덱스와 길이 저장. ex aaa
2. 좌우가 같으며 중앙이 다른 길이가 3인 문자열을 찾아 마찬가지로 vec에 저장. ex aba
3. 지금까지 모은 벡터를 좌우로 확장시켜가며 조건 검사

😀 aaa, aba를 따로 모은다는 발상
