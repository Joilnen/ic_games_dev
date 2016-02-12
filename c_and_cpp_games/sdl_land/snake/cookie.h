#ifndef COOKIE_H
#define COOKIE_H

typedef struct Cookie {
    int x, y;
    SDL_Rect rect;
} Cookie;

Cookie *create_cookie();
void delete_cookie(Cookie *s);
void init_cookie(SDL_Renderer *r, Cookie *);


#endif
