// 문제 링크 https://programmers.co.kr/learn/courses/30/lessons/42748
// K번째수

import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        int[] tmpArr = null;

        int ansIdx = 0;
        for(int i=0; i<commands.length; i++){
            tmpArr = new int[commands[i][1]-commands[i][0]+1];

            for(int idx = commands[i][0]-1; idx<=commands[i][1]-1; idx++){
                tmpArr[idx-commands[i][0]+1] = array[idx];
            }
            Arrays.sort(tmpArr);
            answer[ansIdx++] = tmpArr[commands[i][2]-1];
        }
        return answer;
    }
}

public class Main {
    public static void main(String[] args){
        Solution sol = new Solution();

        int[][] commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
        int[] arr = {1, 5, 2, 6, 3, 7, 4};

        int[] answer = sol.solution(arr, commands);
        for(int ans : answer)
            System.out.print(ans + " ");
    }
}
