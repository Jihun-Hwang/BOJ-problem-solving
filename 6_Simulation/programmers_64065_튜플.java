// 문제 링크 https://programmers.co.kr/learn/courses/30/lessons/64065
// 튜플

import java.util.*;

class Solution {
    public int[] solution(String s) {
        HashMap<Integer, HashMap<Integer, Integer>> parsedMap = new HashMap<>(); // <길이, 파싱된배열>
        char[] inputs = s.toCharArray();

        int curElementLen = 0;
        HashMap<Integer, Integer> parsedElement = null; // 리스트로 간주
        String tmpDigit = "";
        boolean isStartingNewEle = true;  // ',' 가 리스트를 구분하는 것인지 리스트 안에서 원소를 구분하는 것인지

        // 2차원 리스트와 같은 형태로 파싱
        for(int idx = 1; idx<=inputs.length-2; idx++){
            if(inputs[idx] == '{') {
                parsedElement = new HashMap<>();  // 새로운 리스트 생성
                isStartingNewEle = false;
                continue;
            }
            if(inputs[idx] == '}') {
                // 각 리스트에서 가장 마지막 원소에 대해 처리
                parsedElement.put(Integer.parseInt(tmpDigit), Integer.parseInt(tmpDigit));
                tmpDigit = "";
                curElementLen++;

                // 만들어진 리스트를 저장
                parsedMap.put(curElementLen, parsedElement);
                curElementLen = 0;
                isStartingNewEle = true;
                continue;
            }
            if(inputs[idx] == ',' && isStartingNewEle){
                continue;
            }
            if(inputs[idx] == ',' && !isStartingNewEle) {
                parsedElement.put(Integer.parseInt(tmpDigit), Integer.parseInt(tmpDigit));
                tmpDigit = "";
                curElementLen++;
                continue;
            }
            // 숫자인 경우
            tmpDigit += Character.toString(inputs[idx]);
        }

        // 차집함을 이용해 결과 구하기
       int[] answer = new int[parsedMap.size()];
        HashMap<Integer, Integer> diffMap = null;

        // 첫번째 결과 값 저장
        answer[0] = parsedMap.get(1).values().stream().findFirst().get();

        for(int len=2; len<=parsedMap.size(); len++){
            // 차집합 구하기
            diffMap = new HashMap<>(parsedMap.get(len));
            diffMap.entrySet().removeAll(parsedMap.get(len-1).entrySet());

            // 결과 순차적으로 저장
            answer[len-1] = diffMap.values().stream().findFirst().get();
        }

        return answer;
    }
}

public class Main {
    public static void main(String[] args){
        Solution sol = new Solution();
        int[] result = sol.solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
    }
}
