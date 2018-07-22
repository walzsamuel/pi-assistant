import Vue from 'vue';
import Router from 'vue-router';
import Login from '@/views/login/Login.vue';
import Register from '@/views/login/Register.vue';
import Home from '@/views/Home.vue';
import About from '@/views/About.vue';

Vue.use(Router);

export default new Router({
    routes: [
        {
            path: '/',
            name: 'home',
            component: Home,
        },
        {
            path: '/about',
            name: 'about',
            component: About,
        },
        {
            path: '/login',
            name: 'login',
            component: Login,
        },
        {
            path: '/register',
            name: 'register',
            component: Register,
        },
    ],
});
