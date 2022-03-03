#include "pch.h"
#include "FormUI.h"
#include <FormUI.h>
#include "FormCall.h"
using namespace std;
using Form::CustomForm;
using Form::SimpleForm;
//  SimpleForm form("Welcome to shop", "Choose what you want to do...");     // Initialize the form with title and content
//  form.addButton("Buy", "textures/items/apple",                            // Add a button "Buy" with texture image
//      [](Player* pl) { pl->sendText("To buy something..."); })			 // Buy's callback function
//
//      .addButton("Sell", "https://xxx.com/xxx.png",                        // Add a button "Sell" with online image
//          [](Player* pl) { pl->sendText("To sell something..."); })        // Sell's callback function
//
//      .addButton("Settings", "",                                           // Add a button "Settings" with no image
//          [](Player* pl) { pl->sendText("Get into settings..."); })        // Settings's callback function
//
//      .addButton("Exit")                                                   // Add a single button "Exit" 
//      .sendTo(Level::getPlayer("John"));                   // Send the form to a player called "Jim"
//
//
//
//  CustomForm form2("Information Collection Form");                            // Initialize the form with title
//  form2.addLabel("label1", "Personal Information")                            // Add a label shows "Personal Information"
//      .addInput("username", "Your Name")                                      // Add an input line to gather player's name
//      .addDropdown("sex", "Your Sex", { "Male","Female","Secret" })           // Add a dropdown to gather player's sex
//      .addSlider("age", "Your Age", 3, 100)                                   // Add a slider to gather player's age
//  
//      .addLabel("label2", "MC Information")                                   // Add a label shows "MC Information"
//      .addToggle("licensed", "Purchased a licensed Minecraft?", true)         // Add a toggle about whether he buys a licensed mc or not
//      .addStepSlider("ability", "MC Ability", { "Beginner", "Experienced", "Master" })      // Add a step slider shows his game ability
//  
//      .sendTo(Level::getPlayer("yqs112358"),                                  // Send the form to a player called "John"
//          [](Player* player, auto result)                                     // Callback function to process the result
//          {
//              if (result.empty())                                             // He cancelled the form
//                  return;
//              player->sendText("You have commited the form.");
//              player->sendFormattedText("Your name: {}", result["username"]->getString());
//              player->sendFormattedText("Your sex: {}", result["sex"]->getString());
//              player->sendFormattedText("Your age: {}", result["age"]->getNumber());
//              player->sendFormattedText("Your license: {}", result["licensed"]->getBool() ? "yes" : "no");
//              player->sendFormattedText("Your ability: {}:", result["ability"]->getString());
//          });
void formPlayerInfo(Player* ad, Player* pl) {
	SimpleForm playerInfo("玩家信息","");
	playerInfo.sendTo(ad);
}