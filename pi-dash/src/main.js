import Vue from 'vue';
import VueResource from 'vue-resource';
import App from './App.vue';
import router from './router';

Vue.config.productionTip = false;
Vue.use(VueResource);

Vue.component(
    'passport-clients',
    require('./components/passport/Clients.vue'),
);

Vue.component(
    'passport-authorized-clients',
    require('./components/passport/AuthorizedClients.vue'),
);

Vue.component(
    'passport-personal-access-tokens',
    require('./components/passport/PersonalAccessTokens.vue'),
);

new Vue({
    router,
    render: h => h(App),
}).$mount('#app');
