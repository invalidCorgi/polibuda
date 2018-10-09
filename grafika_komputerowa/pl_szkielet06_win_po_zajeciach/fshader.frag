/*#version 330

out vec4 pixelColor; //Zmienna wyjsciowa fragment shadera. Zapisuje sie do niej ostateczny (prawie) kolor piksela

in vec4 l; //Wektor do swiatla w przestrzeni oka
in vec4 n; //Wektor normalny w przestrzeni oka
in vec4 v; //Wektor do obserwatora w przestrzeni oka
in vec2 iTexCoord0; //Wspolrzedne teksturowania
in vec2 iTexCoord1;
in float layer;

//Zmienne reprezentujace jednostki teksturujace
uniform sampler2D textureMap0;
uniform sampler2D textureMap1;

void main(void) {
    vec4 ml=normalize(l);
    vec4 mn=normalize(n);

    float nl=max(dot(mn,ml),0); //Kosinus kata pomiedzy wektorami do swiatla i normalnym

    vec4 fur=texture(textureMap0,iTexCoord0); //futro (jest wlos?)
    vec4 furCol=texture(textureMap1,iTexCoord0); //kolor futra
    vec4 col=furCol;                          //domyœlny kolor
    //Je¿eli nie pierwsza warstwa to dodaj alfa z teks. futra
    if (layer!=0) col=vec4(furCol.rgb,fur.a);
    // Usuñ niewidoczny fragment, Z Bufor pozostanie bez zmian
    if (fur.a==0 && layer!=0) discard;
    pixelColor=col*vec4(nl,nl,nl,1);       //wynikowy kolor
}
*/

#version 330

out vec4 pixelColor;
in vec4 iColor;

void main(void) {
    pixelColor=iColor;
}
