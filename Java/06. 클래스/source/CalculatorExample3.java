public class CalculatorExample3 {
    Calculaotr3 myCalcu = new Calculator3();
    
    //정사각형의 넓이 구하기
    double result1 = myCalcu.arearRectangle(10);
    
    //직사각형의 넓이 구하기
    double result2 = myCalcu.areaRectangle(10, 20);
    
    //결과 출력
    System.out.println("정사각형 넓이=" + result1);
    System.out.println("직사각형 넓이=" + result2);
}