#include<stdio.h>



typedef struct point{
    double x;
    double y;
    } point_t;
typedef struct circle{
    point_t center;
    double radius;
    } circle_t;



int is_in_circle(point_t *p, circle_t *c){
    double x_dist, y_dist;
    x_dist = p->x -c->center.x;
    y_dist = p->y -c->center.y;
    return(x_dist * x_dist + y_dist * y_dist <= c->radius * c->radius);
    }

int main(void){
    point_t  p;
    circle_t c;
    printf("Nhap toa do diem can xet\n");
    scanf("%lf%lf", &p.x, &p.y);
    printf("Nhap toa do tam duong tron\n");
    scanf("%lf%lf", &c.center.x, &c.center.y);
    printf("Nhap do lon ban kinh duong tron\n");
    scanf("%lf", &c.radius);
    if(is_in_circle(&p, &c)) printf("Diem nay thuoc duong tron\n");
    else printf("Diem nay nam ngoai duong tron\n");
    return 0;
}