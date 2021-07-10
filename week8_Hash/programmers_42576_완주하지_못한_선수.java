// 문제 링크 https://programmers.co.kr/learn/courses/30/lessons/42576
// 완주하지 못한 선수

import java.util.HashMap;

class Solution {
    public String solution(String[] participants, String[] completions) {
        HashMap<String, Integer> hashMap = new HashMap<>();

        for(String participant : participants){
            hashMap.put(participant, hashMap.getOrDefault(participant, 0) + 1);
        }

        for(String completion : completions){
            if(hashMap.containsKey(completion)){
                hashMap.put(completion, hashMap.get(completion) - 1);

                if(hashMap.get(completion) == 0)
                    hashMap.remove(completion);
            }
        }

        return hashMap.keySet().stream().findFirst().get();
    }
}

public class Main {
    public static void main(String[] args){
        Solution sol = new Solution();

        String[] participant = {"leo", "kiki", "eden"};
        String[] completion = {"eden", "kiki"};

        String ans = sol.solution(participant, completion);
        System.out.println(ans);
    }
}
