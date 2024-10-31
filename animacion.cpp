#include "animation.h"
#include <iostream>



class Animation {
public:
    Animation(sf::Texture* texture, int initRow, sf::Vector2u _imgCount, float _frameTime, bool ppMode);
    void Update(float deltaTime);
    void setRow(int row);
    void setFrameTime(float _frameTime);
    void setPPMode(bool mode);
    sf::IntRect tRect;

private:
    sf::Vector2u imgCount;
    sf::Vector2u currentImage;
    float totalTime;
    float frameTime;
    bool pingpong;
    bool endloop;
};

class GuiDialog {
public:
    GuiDialog(char* text, sf::Font& font, sf::Vector2f position, sf::Color color, unsigned int csize = 0, float time = 0);
    void Update(float deltaTime);
    void Draw(sf::RenderWindow* window);
    sf::Vector2f getPos();
    void setEnable(bool state);
    bool getEnable();

private:
    bool enable;
    sf::Text dialog;
    float showTime;
    float totalTime;
};

class AnimationProp {
protected:
    sf::Sprite* spr;
    float totalTime;
    float duration;
    bool end;

public:
    AnimationProp(sf::Sprite* _spr, float _duration);
    virtual void Update(float time);
    bool isEnd();
    void Reset();
};

class AnimationPos : public AnimationProp {
public:
    AnimationPos(sf::Sprite* _spr, sf::Vector2f startPos, sf::Vector2f endPos, float duration);
    void Update(float time);
};

class AnimationRot : public AnimationProp {
public:
    AnimationRot(sf::Sprite* _spr, float startPos, float endPos, float duration);
    void Update(float time);
};

class AnimationSiz : public AnimationProp {
public:
    AnimationSiz(sf::Sprite* _spr, sf::Vector2f startPos, sf::Vector2f endPos, float duration);
    void Update(float time);
};

class AnimationPlayer {
public:
    void AddAnimation(AnimationProp* anim);
    void Update(float deltaTime);

private:
    std::vector<AnimationProp*> anims;
    void Reset();
    int currentAnim = 0;
};

#endif // ANIMATION_H_INCLUDED
