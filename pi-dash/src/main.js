import Vue from 'vue';
import VueResource from 'vue-resource';
import BootstrapVue from 'bootstrap-vue/dist/bootstrap-vue.esm';

import './styles';
import App from './App.vue';
import router from './router';
import cfg from './config';


Vue.config.productionTip = false;
Vue.use(VueResource);
Vue.use(BootstrapVue);
Object.defineProperty(Vue.prototype, '$cfg', { value: cfg });

new Vue({
    router,
    render: h => h(App),
}).$mount('#app');
