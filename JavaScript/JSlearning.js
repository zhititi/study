'use strict'
//-----------------------------------------------------------------------------------------------------------------------
//输出格式
var name = '小明';
var age = 20;
var message = '你好, ' + name + ', 你今年' + age + '岁了!'; //用+连接字符串，message = '你好，小明，你今年20岁了!'
//alert(message);                                       //用提醒的方式输出，在html文件中可用
console.log(`你好, ${name}, 你今年${age}岁了!`);         //console用控制台形式在一行内输出，ES6新定义的字符串模板的格式输出。
console.log('你好, ' + name + ', 你今年' + age + '岁了!');//同样的结果

var arr = ['Bart', 'Lisa', 'Adam'];                    //定义arr数组
for (var i in arr){                                    //索引（下标）访问
    console.log(`Hello，${arr[i]}!`);          //注意符号，`  `esc下面的符号
}
//-----------------------------------------------------------------------------------------------------------------------
//数据类型
/*
数据类型有number，字符串，布尔值，null，undefined，对象 等
对象包括了数组。
变量可以是任意数据类型。
*/
//number
123; // 整数123
0.456; // 浮点数0.456
1.2345e3; // 科学计数法表示1.2345x1000，等同于1234.5
-99; // 负数
0xffffff//十六进制
NaN; // NaN表示Not a Number，当无法计算结果时用NaN表示
Infinity; // Infinity表示无限大，当数值超过了JavaScript的Number所能表示的最大值时，就表示为Infinity
//运算
2 / 0; // Infinity
0 / 0; // NaN

null      //表示空值
undefined//表示未定义

//-----------------------------------------------------------------------------------------------------------------------
//对象，容器与访问
var xiaoming = {                                       //JavaScript的对象是一种无序的集合数据类型，它由若干键值对组成。
    name: '小明',
    birth: 1990,
    school: 'No.1 Middle School',
    height: 1.70,
    weight: 65,
    score: null
};
xiaoming.name; // '小明'
xiaoming.birth; // 1990
var xiaohong = {
    name: '小红',
    'middle-school': 'No.1 Middle School'
};
xiaohong['middle-school']; // xiaohong的属性名middle-school不是一个有效的变量，无法使用.操作符，必须用['xxx']来访问
xiaohong['name'];    // '小红'
xiaohong.name;       // 用 .操作符来访问
//访问不存在的属性不报错，而是返回undefined：
/*
具有iterable类型的集合可以通过新的for ... of（SE6新引进的语法）循环来遍历。
for ... in它遍历的实际上是对象的属性名称。
for ... of循环则修复了这些问题，它只循环集合本身的元素
*/
var a={   //一个Array数组实际上也是一个对象，它的每个元素的索引被视为一个属性。
    1:'A',
    2:'B',
    3:'C'
}
var a = ['A', 'B', 'C'];
a.name = 'Hello';
for (var x in a) {
    console.log(x); //结果为 '0', '1', '2', 'name'
}
for (var x of a) {
    console.log(x); // 'A', 'B', 'C'
}
a.forEach(function (element, index, array) {
    // element: 指向当前元素的值
    // index: 指向当前索引
    // array: 指向Array对象本身
    console.log(element + ', index = ' + index);
});

//map的用法
var m = new Map([['Michael', 95], ['Bob', 75], ['Tracy', 85]]); //Map是一组键值对的结构
m.get('Michael'); //用get来访问

//set的用法
var s = new Set(['A', 'B', 'C']);  //Set与Array类似，但Set“没有索引”，因此回调函数的前两个参数都是元素本身
s.forEach(function (element, sameElement, set) {
    console.log(element);
});

//-----------------------------------------------------------------------------------------------------------------------
//函数
/*
执行到return时，函数就执行完毕，并将结果返回。
若没有return语句，函数执行完毕后会返回undefined。
JavaScript的函数也是一个对象，上述定义的abs()函数实际上是一个函数对象，而函数名abs可以视为指向该函数的变量。
JavaScript允许传入任意个参数而不影响调用。

*/
//函数的定义
function abs(x) {
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
}
var abs = function (x) {  //效果相同
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
};                    //注意这里要加一个;表示赋值语句结束
//函数的调用
//JavaScript允许传入任意个参数而不影响调用。
abs(-4,'dsdsd');//4
abs();//此时abs(x)函数的参数x将收到undefined，计算结果为NaN

//为了避免收到undefined，可以进行参数检查
function abs(x) {
    if (typeof x !== 'number') {  //typeof函数返回变量的数据类型
        throw 'Not a number';
    }
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
}
//arguments
//类似Array，只在函数内部起作用，存放当前函数的调用者传入的所有参数。
function foo(x) {
    console.log('x = ' + x); // 10
    for (var i=0; i<arguments.length; i++) {
        console.log('arg ' + i + ' = ' + arguments[i]); // 10, 20, 30
    }
}
foo(10, 20, 30);
/*
结果：
x = 10
arg 0 = 10
arg 1 = 20
arg 2 = 30
*/
//rest
//ES6标准引入了rest参数，是一个数组，存储多余的参数
function foo(a, b,...rest) {   //rest参数必须放在最后，前面需要有...
    console.log('a = ' + a);
    console.log('b = ' + b);
    console.log(rest);
}
foo(1, 2, 3, 4, 5);
// 结果:
// a = 1
// b = 2
// Array [ 3, 4, 5 ]
foo(1);
// 结果:
// a = 1
// b = undefined
// Array []