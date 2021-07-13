// 문제 링크 https://programmers.co.kr/learn/courses/30/lessons/42577
// 전화번호 목록
// 문자열 비교에서 가장 빠른 방법 중 하나는 해쉬를 사용하는 방법..

import java.util.HashMap;

class Solution {
    public boolean solution(String[] phones) {
        HashMap<String, Integer> hashMap = new HashMap<>();

        for(String phone : phones)
            hashMap.put(phone, 0); // 중복을 제거해서 모두 해쉬 맵에 저장

        // 각 전화번호 String을 prefix로 분해해서 다른 전화번호에서 찾기 O(1)
        for(String phone : phones){
            for(int i=1; i<phone.length(); i++){  // 등호를 제외함으로써 자기자신의 해쉬 값과는 비교하지 않도록 함
                if(hashMap.containsKey(phone.substring(0, i)))
                    return false;
            }
        }

        return true;
    }
}

public class Main {
    public static void main(String[] args){
        Solution sol = new Solution();

        String[] phones = {"123","456","789"};
        System.out.println(sol.solution(phones)); // test
    }
}
