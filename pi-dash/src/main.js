import Vue from 'vue';
import VueResource from 'vue-resource';
import BootstrapVue from 'bootstrap-vue/dist/bootstrap-vue.esm';
import { sync } from 'vuex-router-sync';
import './config/styles';

import store from './vuex/store'; // vuex store instance
import router from './vue-router/router'; // vue-router instance

import App from './App.vue';
import cfg from './config/config';

const unsync = sync(store, router); // done. Returns an unsync callback fn


Vue.config.productionTip = false;
Vue.use(VueResource);
Vue.use(BootstrapVue);
Object.defineProperty(Vue.prototype, '$cfg', { value: cfg });

new Vue({
    router,
    store,
    render: h => h(App),
}).$mount('#app');
