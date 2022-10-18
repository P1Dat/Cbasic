/*
• Viết một hàm is_in_circle trả về 1 nếu điểm p bị
bao phủ bởi c. Kiểm tra hàm này trong chương
trình.
*/
#include <stdio.h>
typedef struct a 
{
    double x;
    double y;
} point;

typedef struct b
{
    double radius;
    point pos;
} circle;

int is_in_circle(point *p, circle *I){
        double tmp_x = p->x - I->pos.x;
        double tmp_y = p->y - I->pos.y;
        return (tmp_x * tmp_x + tmp_y * tmp_y <= I->radius * I->radius );
}
int main(){
    point p;
    circle I;
    printf("Enter the position of 'p' form: x y\n");
    scanf("%lf %lf",&p.x,&p.y);
    printf("Enter the radius and center I of circle form: r x y\n");
    scanf("%lf %lf %lf",&I.radius,&I.pos.x,&I.pos.y);
    printf("%d",is_in_circle(&p,&I));
    return 0;
}