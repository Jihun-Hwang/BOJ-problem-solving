// 문제 링크 https://programmers.co.kr/learn/courses/30/lessons/43163
// 단어 변환

import java.util.*;

class Solution {
    boolean visited[] = null;
    String[] words = null;
    int minCount = 100;

    public int solution(String begin, String target, String[] words) {
        visited = new boolean[words.length];
        this.words = words;

        // 정답이 없는 경우 인지 확인
        boolean hasAnswer = false;
        for(String word : words){
            if(word.equals(target)){
                hasAnswer = true;
                break;
            }
        }
        if(hasAnswer == false) return 0;

        dfs(begin, target, 0);

        return minCount;
    }

    private void dfs(String prevStr, String target, int count) {
        if(count >= minCount) return;
        if(prevStr.equals(target)){
            minCount = Math.min(count, minCount);
            return;
        }
        List<Integer> changeableIdxs = getChangableIndexs(prevStr);

        for(int changeableIdx : changeableIdxs){
            if(visited[changeableIdx]) continue;

            visited[changeableIdx] = true;
            dfs(words[changeableIdx], target, count + 1);
            visited[changeableIdx] = false;
        }
    }

    private List<Integer> getChangableIndexs(String from) {
        List<Integer> resultIndex = new ArrayList<>();

        for(int i=0; i<words.length; i++){
            if(visited[i]) continue;

            int count = 0;
            for(int j=0; j<from.length(); j++){
                if(words[i].charAt(j) == from.charAt(j))
                    count++;
            }
            if(count == from.length() - 1) resultIndex.add(i);
        }

        return resultIndex;
    }
}

public class Main {
    public static void main(String[] args){
        Solution sol = new Solution();

        String[] words = {"hot", "dot", "dog", "lot", "log", "cog"};
        int answer = sol.solution("hit", "cog", words);
        System.out.print(answer);
    }
}
