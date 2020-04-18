class CarExample3 {
  public static void main(String[] args) {
    Car myCar = new Car();
    myCar.keyTurnOn();
    myCar.run();
    int speed = myCar.getSpeed();
    System.out.println("현재 속도: " + speed + "km/h");
  }
}