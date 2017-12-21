//
// Created by GXSN-Pro on 2017/12/14.
//

#include <glm/vec3.hpp>
#include "earth.hpp"

namespace OpenEarth {
    static const float MIN_RADIUS  = 1.0f;
    static  float min_zoom  = 1f;
    static  float max_zoom  = 16f;
    static float earth_radius = DEFAULT_RADIUS;
    static float earth_scale  = DEFAULT_SCALE;
    static float earth_zoom   = 1.0f;
    static glm::vec3 center = glm::vec3(0, 0, 0); //球心

    void OpenEarth::Earth::setRadius(float r) {
        earth_radius = r;
    }

    float OpenEarth::Earth::getRadius() {
        return earth_radius;
    }

    bool OpenEarth::Earth::setScale(float scale) {
        assert(scale>0.0f);
        float newScale = earth_scale * scale;
        float newZoom  = earth_zoom;
        if(newScale >= 2.0f){   //[2.0 )
            int zoom = (int)log2f(newScale);
            newZoom += zoom;
            if(newZoom > max_zoom) {
                newZoom = max_zoom;
                newScale = 2.0f;
            }else{
                newScale = earth_radius * newScale / pow(2,newZoom-1); //放大后的球体半径/当前级别的球体半径
            }
        }else if(1.0 <= newScale){                   //[1.0  2.0)

        }else if(0.5 < newScale){                   //(0.5 1.0)
            if(earth_zoom == min_zoom) newScale = 1.0f;
        }else{                                      //(0 0.5)
            int zoom = (int)log2f(newScale);
            newZoom += zoom;
            if(newZoom < min_zoom) {
                newZoom = min_zoom;
                newScale = 1.0f;
            }else{
                newScale = earth_radius * newScale / pow(2,newZoom-1); //缩小后的球体半径/当前级别的球体半径
            }
        }

        earth_scale = newScale;
        if(newZoom!=earth_zoom){
            earth_zoom = newZoom;
            return true;
        }
        return false;
    }

    float OpenEarth::Earth::getScale() {
        return earth_scale;
    }

    glm::vec3 OpenEarth::Earth::getCenter() {
        return center;
    }
}