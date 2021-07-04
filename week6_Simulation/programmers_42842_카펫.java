// 문제 링크 https://programmers.co.kr/learn/courses/30/lessons/42842
// 카펫

class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = {0, 0};
        int x = 3, y = 3, xy;
        xy = brown + yellow; // xy = brown + yellow = 전체넓이

        for(int tmp = 3; ; tmp++){
            if(xy % tmp != 0) continue;

            x = xy / tmp;
            y = tmp;

            if(isValid(x, y, brown, yellow)) break;
        }

        answer[0] = x;
        answer[1] = y;

        return answer;
    }

    private boolean isValid(int x, int y, int brown, int yellow) {
        int tmpBrown = 2 * y + (x - 2) * 2;
        int tmpYellow = (y - 2) * (x - 2);
        if(tmpBrown == brown && tmpYellow == yellow)
            return true;

        return false;
    }
}
public class Main {
    public static void main(String[] args){
        Solution sol = new Solution();
        int[] result = sol.solution(24, 24);
        System.out.println(result[0] + " " + result[1]); // test
    }
}
