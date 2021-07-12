// 문제 링크 
// 프로그래머스 KDT 데모테스트

import java.util.*;

class Solution {
    public int[] solution(int[][] v) {
        int[] answer = new int[2];

        HashMap<Integer, Integer> vertexX = new HashMap<>();
        HashMap<Integer, Integer> vertexY = new HashMap<>();

        for(int i=0; i<3; i++){
            int x = v[i][0];
            int y = v[i][1];

            vertexX.put(x, vertexX.getOrDefault(x, 0) + 1);
            vertexY.put(y, vertexY.getOrDefault(y, 0) + 1);
        }

        for(int key :vertexX.keySet()){
            if(vertexX.get(key) == 1)  // 개수가 1
                answer[0] = key;
        }
        for(int key :vertexY.keySet()) {
            if (vertexY.get(key) == 1)
                answer[1] = key;
        }

        return answer;
    }
}

public class Main {
    public static void main(String[] args){
        Solution sol = new Solution();

        //int[][] input = {{1, 4}, {3, 4}, {3, 10}};
        int[][] input = {{1, 1}, {2, 2}, {1, 2}};

        int answer[] = sol.solution(input);
        System.out.println(answer[0] + ", " + answer[1]);
    }
}
