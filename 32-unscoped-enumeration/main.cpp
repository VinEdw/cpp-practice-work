namespace Monster {
  enum MonsterType {
    orc,
    goblin,
    troll,
    ogre,
    skeleton,
  };
}

int main() {
  [[maybe_unused]] Monster::MonsterType monster { Monster::troll };
  return 0;
}
