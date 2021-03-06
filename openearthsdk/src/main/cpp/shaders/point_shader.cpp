//
// Created by GXSN-Pro on 2018/1/23.
//

#include "point_shader.hpp"

namespace OpenEarth {
    namespace Shaders {
        const char *PointShader::name = "point_shader";
        const char *PointShader::veterxShader = R"SHADER(
                uniform mat4 u_MVPMatrix;
                 attribute vec4 POSITION;
                 attribute vec2 a_TextureCoordinates;
                 varying vec2 v_TextureCoordinates;
                 void main(){
                 gl_Position = u_MVPMatrix*POSITION;
                 v_TextureCoordinates = a_TextureCoordinates;
                 }
        )SHADER";

        const char *PointShader::fragmentShader = R"SHADER(
                precision mediump float;
                 uniform sampler2D u_TextureUnit;
                 varying vec2 v_TextureCoordinates;
                 void main(){
                    gl_FragColor = texture2D(u_TextureUnit, v_TextureCoordinates);
                 }
        )SHADER";
    }
}