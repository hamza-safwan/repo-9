import scala.io.StdIn

// Define a class for the ATM
class ATM(var balance: Double) {
  // Method to check balance
  def checkBalance(): Unit = {
    println(s"Your current balance is: $balance")
  }

  // Method to deposit funds
  def deposit(amount: Double): Unit = {
    balance += amount
    println(s"Deposited $amount. Your new balance is: $balance")
  }

  // Method to withdraw funds
  def withdraw(amount: Double): Unit = {
    if (amount <= balance) {
      balance -= amount
      println(s"Withdrew $amount. Your new balance is: $balance")
    } else {
      println("Insufficient funds!")
    }
  }
}

object Main {
  def main(args: Array[String]): Unit = {
    // Initialize ATM with starting balance
    val atm = new ATM(1000.0)

    // ATM menu
    var choice = 0
    while (choice != 4) {
      println("\nATM Menu:")
      println("1. Check Balance")
      println("2. Deposit Funds")
      println("3. Withdraw Funds")
      println("4. Exit")
      print("Enter your choice: ")
      choice = StdIn.readInt()

      choice match {
        case 1 =>
          atm.checkBalance()
        case 2 =>
          print("Enter amount to deposit: ")
          val depositAmount = StdIn.readDouble()
          atm.deposit(depositAmount)
        case 3 =>
          print("Enter amount to withdraw: ")
          val withdrawAmount = StdIn.readDouble()
          atm.withdraw(withdrawAmount)
        case 4 =>
          println("Exiting ATM. Goodbye!")
        case _ =>
          println("Invalid choice. Please try again.")
      }
    }
  }
}
