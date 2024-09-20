#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>


int main() {
  //initiate variables
  int price;
  std::string bors;
  long long dollars = 1000;
  long long buyCost;
  long long sellCost;
  long long shares = 0;
  long long days;
  long long dayCount;
  std::string skip;
  int finalChoice;

  std::cout << "How many days would you like?: ";
  std::cin >> days;
  dayCount = days;
  
  


for(int i=0; i < days; i++){
  //changes in stock price
  srand((unsigned) time(0));
    int price = 10 + (rand() % 1000);


  //show your stats like dollars days and shares
  std::cout << "\nYou have " << dollars << "$ in the bank right now.\n";
  std::cout << "\nYou have " << dayCount << " days left to get rich!\n";
  dayCount = dayCount - 1;
  std::cout << "Balance: " << dollars << "$\n";
  std::cout << "Shares: " << shares << "\n\n";

  //give the option for 1 2 or 3
  std::cout << "\nCurrent Apple price is: " << price << "$ Would you like to Buy(1) or Sell(2) Apple stock? Or you can Skip(3) to the next day: ";
  std::cin >> bors;  


  //option 1 buying
  if(bors == "1" and dollars != 0){
    std::cout << "The max amount of shares you can buy is: " << dollars / price << "\n";
    std::cout << "How many shares would you like to buy?: ";
    std::cin >> buyCost;
    if(buyCost > (dollars/price)){
      std::cout << "\n\nYou do not have enough money to buy those shares!\n\n";
      std::cout << "---------------------------------------------------------------------\n\n";
    }else if(buyCost <= (dollars/price)){
    std::cout << "---------------------------------------------------------------------\n\n";
    
    //account for bought shares
    shares = shares + buyCost;
    dollars = dollars - (price * buyCost);
    }
  }
  //option 2 sold shares
  else if(bors == "2" and shares != 0){
    std::cout << "\nHow many shares would you like to sell?: ";
    std::cin >> sellCost;
    if(sellCost > shares){
      std::cout << "\nYOU DO NOT HAVE THAT MANY SHARES TO SELL!!!";
      std::cout << "\n\n---------------------------------------------------------------------\n\n";
    }else if(sellCost <= shares){
    std::cout << "---------------------------------------------------------------------\n\n";
    
    //account for sold shares
    shares = shares - sellCost;
    dollars = dollars + (sellCost * price);
    }
  }
  //option 3 skipping to the next day
  else if(bors == "3"){
    std::cout << "Skipping to the next day.\n";
    std::cout << "---------------------------------------------------------------------\n";

  }else if(dollars == 0){
    std::cout << "You can't buy anymore because you are your balance is 0 so you have to sell";
    std::cout << "\nHow much would you like to sell?: ";
    std::cin >> sellCost;
    std::cout << "---------------------------------------------------------------------\n";
    shares = shares - (sellCost / price);
    dollars = dollars + sellCost;
  }  
  else if(bors == "2" and shares == 0){
    std::cout << "You do not have any shares to sell! And because either you weren't paying attention or you are trying to cheat you will lose a day!\n";
    
  }
    
  if(dayCount == 0){
    if(shares > 0){
    std::cout << "\nWould you like me to convert your shares to dollars using the last share price? Yes(1) No(2): ";
    std::cin >> finalChoice;
    
    if(finalChoice == 1){
      std::cout << "\n\nYou have 0 days left to make money. Lets see how you did!\n";
      dollars = dollars + (shares * price);
      shares = 0;
      std::cout << "\nYour Balance is $" << dollars << " dollars";
      std::cout << "\nYou own " << shares << " shares\n";
    }else if(finalChoice == 2){
      std::cout << "\n\nYou have 0 days left to make money. Lets see how you did!\n";
      std::cout << "\nYour Balance is " << dollars << " dollars\n";
      std::cout << "You own " << shares << " shares\n";
    }else{
      while(finalChoice != 1 && finalChoice != 2){
      std::cout << "\nInvalid responce!\n";
      std::cout << "\nWould you like me to convert your shares to dollars using the last share price? Yes(1) No(2): ";
      std::cin >> finalChoice;
      }
    }
    }else if(shares == 0){
      std::cout << "\n\nYou have 0 days left to make money. Lets see how you did!\n";
      std::cout << "\nYour Balance is " << dollars << " dollars\n";
      std::cout << "You own " << shares << " shares\n";
    }
  }
  
}
}
