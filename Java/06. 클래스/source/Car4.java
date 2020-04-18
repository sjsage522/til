public class Car4 {
    //필드
    String company = "현대자동차";
    String model;
    String color;
    int maxSpeed;

    //생성자
    Car4() {                                            //생성자1번
    }

    Car4(String model) {                                //생성자2번
        this(model, "은색", 250);
    }


    Car4(String model, String color) {                  //생성자3번
        this(model, color, 250);
    }

    Car4(String model, String color, int maxSpeed) {    //생성자4번
        this.model = model;
        this.color = color;
        this.maxSpeed = maxSpeed;
    }
}