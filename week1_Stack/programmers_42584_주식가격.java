// 문제 링크 https://programmers.co.kr/learn/courses/30/lessons/42584
// 주식가격

import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Stack<Integer> stack = new Stack<>();

        for(int i=0; i<prices.length; i++){
            while(!stack.empty() && prices[i] < prices[stack.peek()]){ // 감소하는 경우
                answer[stack.peek()] = i - stack.peek();
                stack.pop();
            }
            stack.add(i);
        }

        while(!stack.empty()){
            answer[stack.peek()] = prices.length - stack.peek() - 1;
            stack.pop();
        }

        return answer;
    }
}

public class Main {
    public static void main(String[] args){
        Solution sol = new Solution();

        int[] input = {1, 2, 3, 2, 3};
        int answer[] = sol.solution(input);

        for(int val : answer)
            System.out.print(val + " ");
    }
}
