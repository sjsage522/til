public class Calculator2 {
  int plus(int x, int y) {
    int result = x + y;
    return result;
  }

  double avg(int x, int y) {
    double sum = plus(x, y);
    double result = sum / 2;
    return result;
  }

  void execute() {
    double result = avg(7, 10);
    println("실행경과: " + result);
  }

  void println(String message) {
    System.out.println(message);
  }
}