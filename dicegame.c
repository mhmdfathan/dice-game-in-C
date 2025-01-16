/* dicegame.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#define WON 1
#define LOSE 0

int diceroll()
{
  int x;
  x = rand() % 6 + 1;
  // printf("This is a randomizer function\n");
  return x;
}

int playGame()
{
  int diceone;
  int dicetwo;
  int algo;
  int sum;
  bool playforpoint = false;
  // int gamestate;
  int result;

  algo = getpid() ^ time(NULL);
  srand(algo);

  printf("~~~DICE GAME~~~\n");
  printf("PRESS [ENTER] TO ROLL\n");
  fgetc(stdin);

  diceone = diceroll();
  dicetwo = diceroll();

  sum = diceone + dicetwo;

  printf("Dice one: %d\n", diceone);
  printf("Dice two: %d\n", dicetwo);
  printf("Sum: %d\n", sum);

  switch (sum)
  {
  case 7:
  case 11:
    result = WON;
    break;
  case 2:
  case 3:
  case 12:
    result = LOSE;
    playforpoint = false;
    break;
  default:
    playforpoint = true;
    printf("Playing for point! press [ENTER] to continue");
    fgetc(stdin);
    break;
  }

  while (playforpoint)
  {
    diceone = diceroll();
    dicetwo = diceroll();

    sum = diceone + dicetwo;

    printf("Dice one: %d\n", diceone);
    printf("Dice two: %d\n", dicetwo);
    printf("Sum: %d\n", sum);
    if (sum == 7 || sum == 11)
    {
      result = WON;
      playforpoint = false;
    }
    else if (sum == 2 || sum == 3 || sum == 12)
    {
      result = LOSE;
      playforpoint = false;
    }
    else
    {
      result = WON;
      playforpoint = false;
    }
  }

  return result;
}

int main()
{
  // fgetc(stdin);
  // int result = playGame();
  // switch (result)
  // {
  // case WON:
  //   printf("Congratulations blud, You won!\n\n");
  //   break;
  // case LOSE:
  //   printf("Man like spursy y'know\n\n");
  //   break;
  // default:
  //   printf("The program crashed blud! Crazy!!!\n\n");
  //   break;
  // }
  // playGame();
  // if (sum == 7 || sum == 11)
  // {
  //   printf("You win!\n");
  // }
  // else if (sum == 2 || sum == 3 || sum == 12)
  // {
  //   printf("You lose! Try again!\n");
  // }
  // else
  // {
  //   gamestate = gamestate + 1;
  //   if (gamestate > 1)
  //   {
  //     printf("You have a full point! You win!\n");
  //     gamestate = 0;
  //   }
  //   else
  //   {
  //     printf("You get a point! roll again for win!\n");
  //   }
  // }
  while (1)
  {
    int result = playGame();
    switch (result)
    {
    case WON:
      printf("Congratulations blud, You won!\n\n");
      break;
    case LOSE:
      printf("You lose man! Go again!\n\n");
      break;
    default:
      printf("The program crashed blud! Crazy!!!\n\n");
      break;
    }
  }
  return 0;
}
