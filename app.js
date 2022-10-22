function decreaseRed() {
	document.getElementById("red1").value = parseInt(red1.value) - 1;
}
function increaseRed() {
	document.getElementById("red1").value = parseInt(red1.value) + 1;
}
function decreaseGreen() {
	document.getElementById("green1").value = parseInt(green1.value) - 1;
}
function increaseGreen() {
	document.getElementById("green1").value = parseInt(green1.value) + 1;
}
function decreaseBlue() {
	document.getElementById("blue1").value = parseInt(blue1.value) - 1;
}
function increaseBlue() {
	document.getElementById("blue1").value = parseInt(blue1.value) + 1;
}

function decreaseCyan() {
	document.getElementById("cyan1").value = parseInt(cyan1.value) - 1;
}
function increaseCyan() {
	document.getElementById("cyan1").value = parseInt(cyan1.value) + 1;
}
function decreaseMagenta() {
	document.getElementById("magenta1").value = parseInt(magenta1.value) - 1;
}
function increaseMagenta() {
	document.getElementById("magenta1").value = parseInt(magenta1.value) + 1;
}
function decreaseYellow() {
	document.getElementById("yellow1").value = parseInt(yellow1.value) - 1;
}
function increaseYellow() {
	document.getElementById("yellow1").value = parseInt(yellow1.value) + 1;
}
function decreaseKey() {
	document.getElementById("key1").value = parseInt(key1.value) - 1;
}
function increaseKey() {
	document.getElementById("key1").value = parseInt(key1.value) + 1;
}
function decreaseHue() {
	document.getElementById("hue1").value = parseInt(hue1.value) - 1;
}

function increaseHue() {
	document.getElementById("hue1").value = parseInt(hue1.value) + 1;
}
function decreaseSaturation() {
	document.getElementById("saturation1").value = parseInt(saturation1.value) - 1;
}
function increaseSaturation() {
	document.getElementById("saturation1").value = parseInt(saturation1.value) + 1;
}
function decreaseLightness() {
	document.getElementById("lightness1").value = parseInt(lightness1.value) - 1;
}
function increaseLightness() {
	document.getElementById("lightness1").value = parseInt(lightness1.value) + 1;
}

function getInputValue1() {
	var inputVal = document.getElementById("redText").value;
	document.getElementById("red1").value = inputVal;
}
function getInputValue2() {
	var inputVal = document.getElementById("greenText").value;
	document.getElementById("green1").value = inputVal;
}
function getInputValue3() {
	var inputVal = document.getElementById("blueText").value;
	document.getElementById("blue1").value = inputVal;
}
function getInputValue4() {
	var inputVal = document.getElementById("cyanText").value;
	document.getElementById("cyan1").value = inputVal;
}
function getInputValue5() {
	var inputVal = document.getElementById("magentaText").value;
	document.getElementById("magenta1").value = inputVal;
}
function getInputValue6() {
	var inputVal = document.getElementById("yellowText").value;
	document.getElementById("yellow1").value = inputVal;
}
function getInputValue6() {
	var inputVal = document.getElementById("keyText").value;
	document.getElementById("key1").value = inputVal;
}
function getInputValue8() {
	var inputVal = document.getElementById("hueText").value;
	document.getElementById("hue1").value = inputVal;
}
function getInputValue9() {
	var inputVal = document.getElementById("saturationText").value;
	document.getElementById("saturation1").value = inputVal;
}
function getInputValue10() {
	var inputVal = document.getElementById("valueText").value;
	document.getElementById("value1").value = inputVal;
}

function RGBWorkFunction() {

	var R = document.getElementById("red1").value;
	document.getElementById("redText").value = R;
	var G = document.getElementById("green1").value;
	document.getElementById("greenText").value = G;
	var B = document.getElementById("blue1").value;
	document.getElementById("blueText").value = B;

	colorSquare.style["backgroundColor"] =
		"rgba(" + R + ", " + G + ", " + B + ")";

	document.getElementById("allCounter1").textContent =
		"(" + R + ", " + G + ", " + B + ")"

	var color1 = RGBtoHSV(R, G, B);
	var color2 = RGBtoCMYK(R, G, B);
}

function CMYKWorkFunction() {
	var C = document.getElementById("cyan1").value;
	document.getElementById("cyanText").value = C;
	var M = document.getElementById("magenta1").value;
	document.getElementById("magentaText").value = M;
	var Y = document.getElementById("yellow1").value;
	document.getElementById("yellowText").value = Y;
	var K = document.getElementById("key1").value;
	document.getElementById("keyText").value = K;

	document.getElementById("allCounter2").textContent =
		"(" + C + ", " + M + ", " + Y + ", " + K + ")"

	var color = CMYKtoRGB(C, M, Y, K);
	colorSquare.style["backgroundColor"] = "rgba(" + color[0] + ", " + color[1] + ", " + color[2] + ")";
	var color2 = RGBtoHSV(color[0], color[1], color[2]);
}

function HSVWorkFunction() {
	var H = document.getElementById("hue1").value;
	document.getElementById("hueText").value = H;
	var S = document.getElementById("saturation1").value;
	document.getElementById("saturationText").value = S;
	var V = document.getElementById("value1").value;
	document.getElementById("valueText").value = V;

	document.getElementById("allCounter3").textContent =
		"(" + H + ", " + S + ", " + V + ")"

	var color = HSVtoRGB(H, S, V);
	colorSquare.style["backgroundColor"] = "rgba(" + color[0] + ", " + color[1] + ", " + color[2] + ")";
	var color2 = RGBtoCMYK(color[0], color[1], color[2]);
}

function RGBtoCMYK(r, g, b) {
	r = r / 255;
	g = g / 255;
	b = b / 255;

	var c, m, y, k;

	k = Math.min(1 - r, 1 - g, 1 - b);
	c = (1 - r - k) / (1 - k);
	m = (1 - g - k) / (1 - k);
	y = (1 - b - k) / (1 - k);

	c = Math.round(c * 100);
	m = Math.round(m * 100);
	y = Math.round(y * 100);
	k = Math.round(k * 100);

	document.getElementById("cyan1").value = c;
	document.getElementById("magenta1").value = m;
	document.getElementById("yellow1").value = y;
	document.getElementById("key1").value = k;

	document.getElementById("cyanText").value = c;
	document.getElementById("magentaText").value = m;
	document.getElementById("yellowText").value = y;
	document.getElementById("keyText").value = k;

	document.getElementById("allCounter2").textContent =
		"(" + c + ", " + m + ", " + y + ", " + k + ")"
}

function CMYKtoRGB(c, m, y, k) {
	c = c / 100;
	m = m / 100;
	y = y / 100;
	k = k / 100;

	var r = 1 - Math.min(1, c * (1 - k) + k);
	var g = 1 - Math.min(1, m * (1 - k) + k);
	var b = 1 - Math.min(1, y * (1 - k) + k);

	r = Math.round(r * 255);
	g = Math.round(g * 255);
	b = Math.round(b * 255);

	document.getElementById("red1").value = r;
	document.getElementById("green1").value = g;
	document.getElementById("blue1").value = b;

	document.getElementById("allCounter1").textContent =
		"(" + r + ", " + g + ", " + b + ")"

	document.getElementById("redText").value = r;
	document.getElementById("greenText").value = g;
	document.getElementById("blueText").value = b;

	var mass = [r, g, b];
	return mass;
}

function RGBtoHSV(r, g, b) {
	r = r / 255;
	g = g / 255;
	b = b / 255;

	var minVal = Math.min(r, g, b);
	var maxVal = Math.max(r, g, b);
	var delta = maxVal - minVal;

	var h, s, v;
	v = maxVal;

	if (delta == 0) {
		h = 0;
		s = 0;
	} else {
		s = delta / maxVal;
		var del_R = (((maxVal - r) / 6) + (delta / 2)) / delta;
		var del_G = (((maxVal - g) / 6) + (delta / 2)) / delta;
		var del_B = (((maxVal - b) / 6) + (delta / 2)) / delta;

		if (r == maxVal) { h = del_B - del_G; }
		else if (g == maxVal) { h = (1 / 3) + del_R - del_B; }
		else if (b == maxVal) { h = (2 / 3) + del_G - del_R; }

		if (h < 0) { h += 1; }
		if (h > 1) { h -= 1; }
	}

	h = Math.round(h * 360);
	s = Math.round(s * 100);
	v = Math.round(v * 100);

	document.getElementById("hue1").value = h;
	document.getElementById("saturation1").value = s;
	document.getElementById("value1").value = v;

	document.getElementById("hueText").value = h;
	document.getElementById("saturationText").value = s;
	document.getElementById("valueText").value = v;

	document.getElementById("allCounter3").textContent =
		"(" + h + ", " + s + ", " + v + ")"
}

function HSVtoRGB(h, s, v) {
	h = h / 360;
	s = s / 100;
	v = v / 100;

	var r, g, b;
	var var_r, var_g, var_b;

	if (s == 0) {
		r = v * 255;
		g = v * 255;
		b = v * 255;
	} else {
		var var_h = h * 6;
		var var_i = Math.floor(var_h);
		var var_1 = v * (1 - s);
		var var_2 = v * (1 - s * (var_h - var_i));
		var var_3 = v * (1 - s * (1 - (var_h - var_i)));

		if (var_i == 0) { var_r = v; var_g = var_3; var_b = var_1 }
		else if (var_i == 1) { var_r = var_2; var_g = v; var_b = var_1 }
		else if (var_i == 2) { var_r = var_1; var_g = v; var_b = var_3 }
		else if (var_i == 3) { var_r = var_1; var_g = var_2; var_b = v }
		else if (var_i == 4) { var_r = var_3; var_g = var_1; var_b = v }
		else { var_r = v; var_g = var_1; var_b = var_2 };

		r = var_r * 255;
		g = var_g * 255;
		b = var_b * 255;

		r = Math.round(r);
		g = Math.round(g);
		b = Math.round(b);

		document.getElementById("red1").value = r;
		document.getElementById("green1").value = g;
		document.getElementById("blue1").value = b;

		document.getElementById("redText").value = r;
		document.getElementById("greenText").value = g;
		document.getElementById("blueText").value = b;

		document.getElementById("allCounter1").textContent =
			"(" + r + ", " + g + ", " + b + ")"
	}
	var mass = [r, g, b];
	return mass;
}
