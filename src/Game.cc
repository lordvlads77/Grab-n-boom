#include "CommonHeaders.hh"
#include "Player.hh"
#include "Animation.hh"
#include "TileGroup.hh"


sf::CircleShape* circle{new sf::CircleShape()};

TextObject* textObj1{new TextObject(ASSETS_FONT_HARRYP, 36, sf::Color::White, sf::Text::Bold)};

sf::Clock* gameClock{new sf::Clock()};
float deltaTime{};
Player* player1{};
GameObject* chest1{};
GameObject* light1{};
GameObject* enemy1{};
GameObject* enemy2{};
GameObject* enemy3{};
GameObject* wall1{};
GameObject* wall2{};
GameObject* wall3{};
GameObject* wall4{};
GameObject* wall5{};
GameObject* wall6Sliced{};
GameObject* wall7Up{};
GameObject* wall8Up{};
GameObject* wall1Down{};
GameObject* wall2Down{};
GameObject* wall3Down{};
GameObject* wall4Down{};
GameObject* wall5Down{};
GameObject* wall6SlicedDown{};
GameObject* wall7Down{};
GameObject* wall8Down{};
GameObject* Pillar1Left{};
GameObject* Pillar2Left{};
GameObject* Pillar3Left{};
GameObject* Pillar1Right{};
GameObject* Pillar2Right{};
GameObject* Pillar3Right{};
GameObject* wall1MidUp{};
GameObject* wall2MidUp{};
Animation* idleAnimation{new Animation()};
Animation* runAnimation{new Animation()};

TileGroup* tileGroup{};
Tile* tile1{};

uint32 flags{};
    //flags += b2Draw::e_aabbBit;
    //flags += b2Draw::e_shapeBit;
    //flags += b2Draw::e_centerOfMassBit;
    //flags += b2Draw::e_pairBit;
    //flags += b2Draw::e_jointBit;

Animation* lightIdle{};
Animation* chestIdle{};
Animation* enemeyIdle{};
Animation* enemyIdle2{};


Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
  event = new sf::Event();
  gravity = new b2Vec2(0.f, 0.f);
  world = new b2World(*gravity);
  drawPhysics = new DrawPhysics(window);
  gameObjects = new std::vector<GameObject*>();
  gameObjectsDeleteList = new std::vector<GameObject*>();

  player1 = new Player(ASSETS_SPRITES, 4.f, 16, 16, 0, 5, 300, 200, 200.f, b2BodyType::b2_dynamicBody, world, window);
  player1->SetTagName("Player");
  chest1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 1, 695, 500, b2BodyType::b2_staticBody, world, window);
  chest1->SetTagName("chest");
  light1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 3, 200, 175, b2BodyType::b2_staticBody, world, window);
  light1->SetTagName("light");
  enemy1 = new GameObject(ASSETS_SPRITES, 3.f, 16, 16, 0, 3, 350, 200,b2BodyType::b2_staticBody, world, window);
  enemy1->SetTagName("enemy");
  enemy2 = new GameObject(ASSETS_SPRITES, 3.f, 16, 16, 0, 3, 695, 300, b2BodyType::b2_staticBody, world, window);
  enemy2->SetTagName("enemy2");
  wall1 = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 100, 65, b2BodyType::b2_staticBody, world, window);
  wall1->SetTagName("WallHorUp1");
  wall2 = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 225, 65, b2BodyType::b2_staticBody, world, window);
  wall2->SetTagName("WallHorUp2");
  wall3 = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 350, 65, b2BodyType::b2_staticBody, world, window);
  wall3->SetTagName("WallHorUp3");
  wall4 = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 475, 65, b2BodyType::b2_staticBody, world, window);
  wall4->SetTagName("WallHorUp4");
  wall5 = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 600, 65, b2BodyType::b2_staticBody, world, window);
  wall5->SetTagName("WallHorUp5");
  wall6Sliced = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 725, 65, b2BodyType::b2_staticBody, world, window);
  wall6Sliced->SetTagName("WallHor6UpSliced");
  wall7Up = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 850, 65, b2BodyType::b2_staticBody, world, window);
  wall7Up->SetTagName("Wall7HorUp");
  wall8Up = new GameObject(ASSETS_TILES, 4.f, 8, 32, 0, 0, 928, 65, b2BodyType::b2_staticBody, world, window);
  wall8Up->SetTagName("Wall8HorUp");
  wall1Down = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 100, 875, b2BodyType::b2_staticBody, world, window);
  wall1Down->SetTagName("WallHorDown1");
  wall2Down = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 225, 875, b2BodyType::b2_staticBody, world, window);
  wall2Down->SetTagName("WallHorDown2");
  wall3Down = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 350, 875, b2BodyType::b2_staticBody, world, window);
  wall3Down->SetTagName("WallHorDown3");
  wall4Down = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 475, 875, b2BodyType::b2_staticBody, world, window);
  wall4Down->SetTagName("WallHorDown4");
  wall5Down = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 600, 875, b2BodyType::b2_staticBody, world, window);
  wall5Down->SetTagName("WallHorDown5");
  wall6SlicedDown = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 725, 875, b2BodyType::b2_staticBody, world, window);
  wall6SlicedDown->SetTagName("WallHor6DownSliced");
  wall7Down = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 850, 875, b2BodyType::b2_staticBody, world, window);
  wall7Down->SetTagName("Wall7DownHor");
  wall8Down = new GameObject(ASSETS_TILES, 4.f, 8, 32, 0, 0, 928, 875, b2BodyType::b2_staticBody, world, window);
  wall8Down->SetTagName("Wall8HorDown");
  Pillar1Left = new GameObject(ASSETS_TILES, 4.f, 16, 16, 13, 13, 100, 300, b2BodyType::b2_staticBody, world, window);
  Pillar1Left->SetTagName("Pillar1Left");
  Pillar2Left = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 100, 475, b2BodyType::b2_staticBody, world, window);
  Pillar2Left->SetTagName("Pillar2Left");
  Pillar3Left = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 100, 650, b2BodyType::b2_staticBody, world, window);
  Pillar3Left->SetTagName("Pillar3Left");
  Pillar1Right = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 900, 275, b2BodyType::b2_staticBody, world, window);
  Pillar1Right->SetTagName("Pillar1Right");
  Pillar2Right = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 900, 475, b2BodyType::b2_staticBody, world, window);
  Pillar2Right->SetTagName("Pillar2Right");
  Pillar3Right = new GameObject(ASSETS_TILES, 4.f, 16, 32, 13, 6, 900, 650, b2BodyType::b2_staticBody, world, window);
  Pillar3Right->SetTagName("Pillar3Right");
  wall1MidUp = new GameObject(ASSETS_TILES, 4.f, 32, 32, 0, 0, 375  , 375, b2BodyType::b2_staticBody, world, window);
  wall1MidUp->SetTagName("Wall1MidUp");
  tileGroup = new TileGroup(window, 12, 12, ASSETS_MAPS, 5.3f, 16, 16, ASSETS_TILES);

  contactEventManager = new ContactEventManager(gameObjects, gameObjectsDeleteList);


  lightIdle = new Animation(light1->GetSprite(), 6, 11, 0.1f, 3);
  chestIdle = new Animation(chest1->GetSprite(), 6, 13, 0.1f, 1);
  enemeyIdle = new Animation(enemy1->GetSprite(), 0, 5, 0.1f, 3);
  enemyIdle2 = new Animation(enemy2->GetSprite(), 0, 5, 0.1f, 3);

}

Game::~Game()
{
}

//Starting things
void Game::Start()
{
  flags += b2Draw::e_shapeBit;
  world->SetDebugDraw(drawPhysics);
  drawPhysics->SetFlags(flags);
  world->SetContactListener(contactEventManager);

  AddGameObject(player1);
  AddGameObject(chest1);
  AddGameObject(light1);
  AddGameObject(enemy1);
  AddGameObject(enemy2);
  AddGameObject(wall1);
  AddGameObject(wall2);
  AddGameObject(wall3);
  AddGameObject(wall4);
  AddGameObject(wall5);
  AddGameObject(wall6Sliced);
  AddGameObject(wall7Up);
  AddGameObject(wall8Up);
  AddGameObject(wall1Down);
  AddGameObject(wall2Down);
  AddGameObject(wall3Down);
  AddGameObject(wall4Down);
  AddGameObject(wall5Down);
  AddGameObject(wall6SlicedDown);
  AddGameObject(wall7Down);
  AddGameObject(wall8Down);
  AddGameObject(Pillar1Left);
  AddGameObject(Pillar2Left);
  AddGameObject(Pillar3Left);
  AddGameObject(Pillar1Right);
  AddGameObject(Pillar2Right);
  AddGameObject(Pillar3Right);
  AddGameObject(wall1MidUp);
  textObj1->SetTextStr("Arde mi Poderoso Cosmo Dorado!!!");
  idleAnimation = new Animation(player1->GetSprite(), 0, 5, 0.05f, 5);
  runAnimation = new Animation(player1->GetSprite(), 0, 5, 0.08f, 6);

  /*circle->setRadius(2.f);
  circle->setFillColor(sf::Color::Green);
  circle->setOutlineColor(sf::Color::Green);*/
}

void Game::Initialize()
{
  Start();
  MainLoop();
}

void Game::UpdatePhysics()
{
  world->ClearForces();
  world->Step(deltaTime, 8, 8);
}

//Logic, animations, etc
void Game::Update()
{
  deltaTime = gameClock->getElapsedTime().asSeconds();
  gameClock->restart();

  for(auto &gameObject : *gameObjects)
  {
    gameObject->Update(deltaTime);
  }

  //circle->setPosition(player1->GetSprite()->getPosition());

  lightIdle->Play(deltaTime);
  chestIdle->Play(deltaTime);
  enemeyIdle->Play(deltaTime);
  enemyIdle2->Play(deltaTime);

  if(std::abs(InputSystem::Axis().x) > 0 || std::abs(InputSystem::Axis().y) > 0)
  {
    runAnimation->Play(deltaTime);
  }
  else
  {
    idleAnimation->Play(deltaTime);
  }
}

void Game::MainLoop()
{
  while (window->isOpen())
  {
    while(window->pollEvent(*event))
    {
      if(event->type == sf::Event::Closed)
      {
        window->close();
      }
    }

    UpdatePhysics();
    Input();
    Update();
    Render();
  }
  Destroy();
}

void Game::Render()
{
  for(auto& gameobject: *gameObjectsDeleteList)
  {
      gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), gameobject), gameObjects->end());
      delete gameobject;
  }
  gameObjectsDeleteList->clear();

  window->clear(sf::Color::Black);
  Draw();
  window->display();
}

//Drawing sprites or geometry.
void Game::Draw()
{
  //player1->Draw();
  //window->draw(*circle);

  tileGroup->Draw();
  //tile1->Draw();

  for(auto &gameObject : *gameObjects)
  {
    gameObject->Draw();
  }

  window->draw(*textObj1->GetText());
  //world->DebugDraw();
}

//Keyboard, joysticks, etc.
void Game::Input()
{
  //player1->Move();
}

void Game::Destroy()
{
  delete window;
  delete event;
}

void Game::AddGameObject(GameObject* gameObject)
{
  gameObjects->push_back(gameObject);
}