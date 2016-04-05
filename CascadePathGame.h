#ifndef CASCADEPATHGAME_h
#define CASCADEPATHGAME_h

#include "ArduboyLowMem.h"
#include "DefinesImagesAndSounds.h"

enum CPGFacings {
  CPGNoface=0,
  CPGUp,
  CPGDown,
  CPGLeft,
  CPGRight,
};
enum CPGSpriteTypes {
  CPGPlayer,
  CPGBullet,
  CPGPlant,
  CPGAnimal,
  CPGSquirrel,
  CPGDeer,
  CPGBuffalo,
};

enum CPGGameStates {
  CPGOff = 0,
  CPGTravel,
  CPGLandmark,
  CPGShop,
  CPGHunt
};
enum CPGInventorySlots {
  CPGOxen = 0,
  CPGClothing,
  CPGParts,
  CPGBullets,
  CPGFood,
  CPGInventoryNum
};
enum CPGButtons {
  ButtonLeft = 0,
  ButtonUp,
  ButtonRight,
  ButtonDown,
  ButtonB,
  ButtonA,
  NumButtons
};

struct Settler {
	char name[8];
	int health;
	uint8_t status;
};

class CPGSprite {
  public:
    CPGSprite( int tx, int ty, const unsigned char * ttile, byte ttype, byte tfacing );
    void                  AddSprite( int tx, int ty, const unsigned char * ttile, byte ttype, byte tfacing );
    bool                  CycleNext( CPGSprite * First );
    void                  Draw( ArduboyLowMem * d );
    void                  DeleteNext();
    bool                  IsOffscreen();
    bool                  IsIn( int tX, int tY );
    int                   x, y;
    uint8_t               w, h, speed, frame, maxFrame;
    byte                  facing;
    byte                  type;
    int                   meat;
    const unsigned char * tile;
    CPGSprite           * next;
};

class CascadePathGame {
  public:
    CascadePathGame( ArduboyLowMem * display );
    void  Begin( );
    void  DrawTitleScreen( );
    void  Cycle( );

    void  MenuDraw( uint8_t y, uint8_t h, uint8_t scrollIndex, uint8_t start, uint8_t menuMax );
    int   GameMenu( int y, uint8_t ArrayIndex, uint8_t Selections );
    void  MainMenu( );
    void  ShopMenu( );
    void  BuyDialog( uint8_t InventorySlot );
//  void  SubMenuAnimate( uint8_t x, uint8_t y, uint8_t h );

    int   offset( uint8_t digits, int value );
    void  WaitForTap( );
    void  LoadStringBuffer( const unsigned char * const * TargetArray, int Index );
    void  PrintBufferAt( int x, int y );
    int   SizeOfBuffer( );

    void  QuickNewGame( );
    void  CustomNewGame( );
    void  NameEntry( int x, int y, uint8_t index );
    void  MonthEntry( );
    void  LongTextSetup( );

    void  Travel( );
    void  TravelDraw( bool osc, uint8_t mountainOffset, uint8_t grassOffset );
    void  DrawNextStop( );
    void  DrawDate( uint8_t y );
    void  IncDate( bool rest );

    int   AliveSettlers( );
    void  DamageSettlers( int Damage );
    void  FeedSettlers( );

    void  Landmark( );
    void  RiverDialog( );
    void  RiverCrossing( uint8_t action, float riverHeight );
    void  RiverCrash( float riverHeight );
    void  RiverLoss( );
    void  DrawLocation( uint8_t y );
    void  NextLocation( );
    void  WeatherMachine( );
    
    void  Hunt( );

    void  Rest( );
    
    void  FadeIn( uint8_t pMax );
    void  PatternWipe( );
    void  BlackoutBox( int y, int h );
    void  SetAndPrint( int x, int y, const __FlashStringHelper* text );
    void  SetAndPrint( int x, int y, int i );
    void  DrawStripedBitmap( int tX, int tY, const uint8_t * address );

    void  ProcessButtons( );
    void  ButtonPress( uint8_t pButton );
    void  ButtonRelease( uint8_t pButton );
    bool  ButtonOffCD( );
    void  ActivateButtonCD( );
    bool  pressedCD( uint8_t buttons );

   
    ArduboyLowMem * Display;
    bool            ButtonState[ NumButtons ];
    long            LastButtonPress;
    char            StringBuffer[StringBufferSize];
    
    byte            GameState;
    Settler         Settlers[ NumSettlers ];
    uint8_t         Profession, Location, Weather, Day, Month, Pace, Ration;
    int             Year;
    int             Money;
    int             Inventory[ CPGInventoryNum ];
    float           DistanceToNextLandmark;
    float           Distance;
  
};

#endif
