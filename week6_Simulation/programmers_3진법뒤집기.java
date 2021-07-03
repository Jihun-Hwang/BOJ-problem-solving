// 문제 링크 https://programmers.co.kr/learn/courses/30/lessons/68935
// 3진법 뒤집기

class Solution {
    public int solution(int n) {
        int answer = 0;
        String resultOfBase3 = "";

        while(n != 0){
            resultOfBase3 += n % 3;   // 0012
            n = n / 3;
        }

        StringBuffer sb = new StringBuffer(resultOfBase3);
        resultOfBase3 = sb.reverse().toString();   // 1200

        int index = 0;
        for(char curNumber : resultOfBase3.toCharArray()){
            int curDigit = curNumber - '0';  // char to int
            answer += (int)Math.pow(3, index++) * curDigit;
        }

        return answer;
    }
}

public class Main {
    public static void main(String[] args){
        Solution sol = new Solution();
        System.out.println(sol.solution(45)); // test
    }
}
