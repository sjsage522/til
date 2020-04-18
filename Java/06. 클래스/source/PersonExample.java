public class PersonExample {
    public static void main(String[] args) {
        Person p1 = new Person("123456-1234567", "계백");

        System.out.println(p1.nation);
        System.out.println(p1.ssn);
        System.out.println(p1.name);

        //p1.nation = "usa"; //final 필드는 값 수정 불가
        //p1.ssn = "654321-7654321";
        p1.name = "을지문덕";
    }
}