// 문제 링크 https://programmers.co.kr/learn/courses/30/lessons/42840
// 모의고사

import java.util.*;

class Solution {
    public int[] solution(int[] testAnswers) {
        int[][] studentPatterns = {
                {1, 2, 3, 4, 5},
                {2, 1, 2, 3, 2, 4, 2, 5},
                {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
        };
        int[] studentPoints = new int[3];

        // 채점
        for(int i=0; i<testAnswers.length; i++){
            int tmpAnswer = testAnswers[i];

            if(tmpAnswer == studentPatterns[0][i%5])
                studentPoints[0]++;
            if(tmpAnswer == studentPatterns[1][i%8])
                studentPoints[1]++;
            if(tmpAnswer == studentPatterns[2][i%10])
                studentPoints[2]++;
        }

        // 최고 점수 구하기
        int maxPoint = studentPoints[0] <= studentPoints[1] ? studentPoints[1] : studentPoints[0];
        maxPoint = maxPoint <= studentPoints[2] ? studentPoints[2] : maxPoint;

        // 최고 점수 학생 번호 저장
        List<Integer> maxPointStudents = new ArrayList<>();
        for(int student=1; student<=3; student++){
            if(studentPoints[student-1] == maxPoint)
                maxPointStudents.add(student);
        }

        // 학생번호 오름차순 정렬 및 배열로 변환
        Collections.sort(maxPointStudents);
        int[] answer = new int[maxPointStudents.size()];
        for(int i=0; i<maxPointStudents.size(); i++)
            answer[i] = maxPointStudents.get(i);

        return answer;
    }
}

public class Main {
    public static void main(String[] args){
        Solution sol = new Solution();

        int[] input = {1,3,2,4,2};
        int answer[] = sol.solution(input);

        for(int val : answer)
            System.out.print(val + " ");
    }
}
