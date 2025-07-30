#include "rgb_matrix.h"
#include "timer.h"
#include "print.h"
#include "rgb_light_mode.h"
static uint32_t scan_time;
void rgblight_effect_rainbow_swirl2(void) {
    static uint8_t r[] =   {0,60,50};
    static uint8_t g[] =   {0,10,20};
    static uint8_t b[] =   {0,0,0};
    static uint8_t dir[] = {1,1,1};

    for(uint8_t i = 0; i< 3; i++){
        rgb_matrix_set_color(2-i,r[i],g[i],b[i]);
    }

    if (timer_elapsed32(scan_time) < 5)
        return;

    scan_time = timer_read32();
    for(uint8_t i = 0; i< 3; i++){	
		
        if (dir[i] == 1){
			if (g[i] <= 69) g[i]+=1;
			
			else {
				g[i] = 70;
				dir[i] = 2;
			}
			r[i] = 70- g[i];
			b[i] = 0;
		} 
		
		else if (dir[i] == 2){
			if (b[i] <= 69) b[i]+=1;
		
			else {
				b[i] = 70;
				dir[i] = 0;
			}
			g[i] = 70- b[i];
			r[i] = 0;
		} 
		
		else if (dir[i] == 0){
			if (r[i] <= 69) r[i]+=1;
			else{
				r[i] = 70;
				dir[i] = 1;
			}
			b[i] = 70- r[i];
			g[i] = 0;
		} 
	}
}

void rgblight_effect_breathing1(void) {
    static uint8_t val;
    static bool breathing_direction = false;
    RGB rgb = {150,0,150};
    uprintf("confinfo.rgb_color1 = %d\r\n",confinfo.rgb_color);
    switch (confinfo.rgb_color)
    {
        case 0:{
            HSV hsv = {HSV_RED};  // 红色
            hsv.v = val;
            rgb = hsv_to_rgb(hsv);
        }break;
        case 1:{
            HSV hsv = {HSV_GREEN};  // 绿色
            hsv.v = val;
            rgb = hsv_to_rgb(hsv);
        }break;
        case 2:{
            HSV hsv = {HSV_BLUE};  // 蓝色
            hsv.v = val;
            rgb = hsv_to_rgb(hsv);
        }break;
        case 3:{
            HSV hsv = {HSV_YELLOW};  // 黄色
            hsv.v = val;
            rgb = hsv_to_rgb(hsv);
        }break;
        case 4:{
            HSV hsv = {HSV_PURPLE};  // 紫色
            hsv.v = val;
            rgb = hsv_to_rgb(hsv);
        }break;
        case 5:{
            HSV hsv = {HSV_CYAN};  // 青色
            hsv.v = val;
            rgb = hsv_to_rgb(hsv);
        }break;
        case 6:{
            HSV hsv = {HSV_WHITE};  // 白色
            hsv.v = val;
            rgb = hsv_to_rgb(hsv);
        }break;
        default:{
            HSV hsv = {HSV_WHITE};  // 红色
            hsv.v = val;
            rgb = hsv_to_rgb(hsv);    
        }break;
    }
    rgb_matrix_set_color(0,rgb.r,rgb.g,rgb.b);
    rgb_matrix_set_color(1,rgb.r,rgb.g,rgb.b);
    rgb_matrix_set_color(2,rgb.r,rgb.g,rgb.b);
    
    if (timer_elapsed32(scan_time) >= 2) {
        scan_time = timer_read32();
        if (!breathing_direction){
            if (val <= 149) val+=1;
            else {val = 150;breathing_direction = true;}
        }
        else{
             if (val >= 1) val-=1;
            else {val = 0;breathing_direction = false;}
        }
    }

}

void paoma(void){
    static uint8_t i;
    
    for (uint8_t j = 0;j < 3;j++){
        if (j == i || j == i - 1){
            switch (confinfo.rgb_color)
            {
            case 0:
                rgb_matrix_set_color(j,RGBLIGHT_LIMIT_VAL,0,0);
                break;
            case 1:
                rgb_matrix_set_color(j,0,RGBLIGHT_LIMIT_VAL,0);
                break;
            case 2:
                rgb_matrix_set_color(j,0,0,RGBLIGHT_LIMIT_VAL);
                break;
            case 3:
                rgb_matrix_set_color(j,RGBLIGHT_LIMIT_VAL,RGBLIGHT_LIMIT_VAL,0);
                break;
            case 4:
                rgb_matrix_set_color(j,RGBLIGHT_LIMIT_VAL,0,RGBLIGHT_LIMIT_VAL);
                break;
            case 5:
                rgb_matrix_set_color(j,0,RGBLIGHT_LIMIT_VAL,RGBLIGHT_LIMIT_VAL);
                break;
            case 6:
                rgb_matrix_set_color(j,RGBLIGHT_LIMIT_VAL,RGBLIGHT_LIMIT_VAL,RGBLIGHT_LIMIT_VAL);
                break;
            default:
                break;
            }
           
        }
        else rgb_matrix_set_color(j,0,0,0);
    }
    if (!scan_time) scan_time = timer_read32();
    if (timer_elapsed32(scan_time) >= 200) {
        scan_time = timer_read32();
        i++;
        if (i > 3) i = 0;
    }
}

void changliang(void){
    for(uint8_t j = 0;j<3;j++){
        switch (confinfo.rgb_color)
            {
            case 0:
                rgb_matrix_set_color(j,RGBLIGHT_LIMIT_VAL,0,0);
                break;
            case 1:
                rgb_matrix_set_color(j,0,RGBLIGHT_LIMIT_VAL,0);
                break;
            case 2:
                rgb_matrix_set_color(j,0,0,RGBLIGHT_LIMIT_VAL);
                break;
            case 3:
                rgb_matrix_set_color(j,RGBLIGHT_LIMIT_VAL,RGBLIGHT_LIMIT_VAL,0);
                break;
            case 4:
                rgb_matrix_set_color(j,RGBLIGHT_LIMIT_VAL,0,RGBLIGHT_LIMIT_VAL);
                break;
            case 5:
                rgb_matrix_set_color(j,0,RGBLIGHT_LIMIT_VAL,RGBLIGHT_LIMIT_VAL);
                break;
            case 6:
                rgb_matrix_set_color(j,RGBLIGHT_LIMIT_VAL,RGBLIGHT_LIMIT_VAL,RGBLIGHT_LIMIT_VAL);
                break;
            default:
                break;
            }
    }
}
