public class IfNestedExample {
    public static void main(String[] args) {
        int score = (int)(Math.random()*20) + 81; //Math.random()는 0이상 1.0미만의 														double 타입의 난수를 하나 리턴
        System.out.println("점수: " + score);

        String grade;

        if(score >= 90) {
            if(score >= 95) {
                grade = "A+";
            }
            else {
                grade = "A";
            }
        }
        else {
            if(score >= 85) {
                grade = "B+";
            }
            else {
                grade = "B";
            }
        }

        System.out.println("학점: " + grade);
    }
}