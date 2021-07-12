// 문제 링크 https://programmers.co.kr/learn/courses/30/lessons/42839
// 소수찾기

import java.util.*;

class Solution {
    HashMap<Integer, Integer> resultMap = new HashMap<>();
    boolean isVisited[] = new boolean[10];

    public int solution(String numbers) {
        for(int i=0; i<numbers.length(); i++){
            backtrack(numbers, "", i+1); // 전체 대상, 붙일 문자열, 만들 문자열 길이
        }

        int ansCount = 0;
        for(int number : resultMap.keySet()){
            if(isPrime(number)) ansCount++;
        }

        return ansCount;
    }

    /**
     * 가능한 모든 조합으로 숫자 만들기
     * @param numbers : 전체 문자열
     * @param tmpStr : 현재 조합중인 문자열
     * @param len : 만들어질 문자열의 길이
     */
    private void backtrack(String numbers, String tmpStr, int len) {
        if(tmpStr.length() == len){
            int toNumber = Integer.parseInt(tmpStr);
            resultMap.put(toNumber, toNumber);

            return;
        }

        for(int i=0; i<numbers.length(); i++){
            if(isVisited[i]) continue;

            isVisited[i] = true;
            tmpStr += (numbers.charAt(i) + "");

            backtrack(numbers, tmpStr, len);

            tmpStr = tmpStr.substring(0, tmpStr.length() - 1);
            isVisited[i] = false;
        }
    }

    private boolean isPrime(int number) {
        if(number == 0 || number == 1) return false;

        for(int div = 2; div<=number/2; div++){
            if(number % div == 0) return false;
        }

        return true;
    }
}

public class Main {
    public static void main(String[] args){
        Solution sol = new Solution();

        int answer = sol.solution("011");
        System.out.print(answer);
    }
}
