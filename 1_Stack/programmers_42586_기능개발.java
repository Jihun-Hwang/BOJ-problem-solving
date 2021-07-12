// 문제 링크 https://programmers.co.kr/learn/courses/30/lessons/42586
// 기능개발

import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        Stack<Integer> stack = new Stack<>();

        for(int i=progresses.length-1; i>=0; i--){
            stack.add(
                    (100 - progresses[i]) / speeds[i]
                    + ((100 - progresses[i]) % speeds[i] > 0 ? 1 : 0)
            );
        }

        List<Integer> answerList = new ArrayList<>();

        while(!stack.empty()){
            int deployOffset = 1;
            int top = stack.pop();

            while(!stack.empty() && top >= stack.peek()){
                deployOffset++;
                stack.pop();
            }

            answerList.add(deployOffset);
        }

        int[] answer = new int[answerList.size()];
        for(int i=0; i<answerList.size(); i++){
            answer[i] = answerList.get(i);
        }

        return answer;
    }
}

public class Main {
    public static void main(String[] args){
        Solution sol = new Solution();

        int[] progresses = {93, 30, 55};
        int[] speeds = {1, 30, 5};

        int answer[] = sol.solution(progresses, speeds);

        for(int val : answer)
            System.out.println(val);
    }
}
