# Blackjack
A simple in-console Blackjack application to refresh C++ memory management and OOP skills. The User starts with $500 funds to play the game and can bet any amount within their funds. If the User uses all of their funds in one round and loses, that will then lead to going bankrupt which will result in a Gameover.

# How to Play #
Follows the normal rules of Blackjack: <br />
  (1) User makes bet within their $funds. Betting all funds means going ALL IN which can lead to Bankruptcy if they lose that round. <br />
  (2) The Dealer deals 2 cards to the User and themselves. Cards are displayed, but ONE of the Dealer's card is not shown, only the first one is shown. <br />
  (3) HandValues of both User and dealer displayed. If either hand contains an ace, it displays both possible values as the following: "1 OR 11" meaning you use either value as you want. <br />
  (4) User chooses to either: <br />
            'hit': receive another card from the dealer, <br />
            'stand': keep the following hand and end the round. <br />
  (5) Once User chooses 'stand', the Dealer then receives their own cards to try to beat the User or stands if their Hand is already greater than the Users. <br />
  (6) Both Handvalues are displayed to the console and a winner is announced. If User wins, they receive 2x their bet made and can continue the game or type 'q' to quit. <br />

# Demonstration #
<h4> Welcome Screen and Making a Bet</h4>
<img src='/Preview/Welcome.png' title='' width='' alt='' />

<h4> Bet Made and Cards Drawn </h4>
<img src='/Preview/BetMade.png' title='' width='' alt='' />

<h4> Winning a Round </h4>
<img src='/Preview/Win.png' title='' width='' alt='' />

<h4> Bankruptcy and Gameover </h4>
<img src='/Preview/Bankrupt.png' title='' width='' alt='' />
