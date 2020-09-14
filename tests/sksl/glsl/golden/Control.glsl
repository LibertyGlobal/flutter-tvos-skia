
precision mediump float;
precision mediump sampler2D;
out mediump vec4 sk_FragColor;
void main() {
    if (sqrt(2.0) > 5.0) {
        sk_FragColor = vec4(0.75);
    } else {
        discard;
    }
    highp int i = 0;
    while (i < 10) {
        sk_FragColor *= 0.5;
        i++;
    }
    do {
        sk_FragColor += 0.25;
    } while (sk_FragColor.x < 0.75);
    for (highp int i = 0;i < 10; i++) {
        if (i % 2 == 1) break; else continue;
    }
    return;
}
