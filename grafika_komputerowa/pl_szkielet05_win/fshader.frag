#version 330

uniform sampler2D textureMap0;
uniform sampler2D textureMap1;

out vec4 pixelColor; //Zmienna wyjsciowa fragment shadera. Zapisuje sie do niej ostateczny (prawie) kolor piksela

//in vec4 iC; //Zmienna interpolowana - kolor wyliczony w vertex shaderze
in vec4 l;
in vec4 n;
in vec4 v;
in vec2 iTexCoord0;

float toonify(float a){
    return round(8*a)/8;
}

void main(void) {
    vec4 ka=vec4(0,0,0,0); //Kolor obiektu w swietle otoczenia
    vec4 kd=texture(textureMap0,iTexCoord0); //Kolor obiektu w swietle rozproszonym
    //vec4 ks=vec4(1,1,1,0);
    vec4 ks=texture(textureMap1,iTexCoord0);;

    vec4 la=vec4(0,0,0,0); //Kolor swiatla otoczenia
    vec4 ld=vec4(1,1,1,1); //Kolor swiatla rozpraszanego
    vec4 ls=vec4(1,1,1,0);

    vec4 ml=normalize(l);
    vec4 mn=normalize(n);
    vec4 mv=normalize(v);

    vec4 r=reflect(-ml,mn);

    float rv=pow(max(dot(r,v),0),10);
    float nl=max(dot(n,l),0); //Kosinus kata pomiedzy wektorami do swiatla i normalnym

    //nl=toonify(nl);
    //rv=toonify(rv);

	pixelColor=ka*la+kd*ld*vec4(nl,nl,nl,1)+ks*ls*vec4(rv,rv,rv,0); //Lambertowski model swiatla rozproszonego
    //pixelColor=vec4(0,1,0,1);
}
