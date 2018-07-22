<template>
    <div id="nav">
        <router-link to="/">Home</router-link> |
        <router-link to="/login" v-if="!isLoggedIn">Login</router-link> |
        <router-link to="/register" v-if="!isLoggedIn">Register</router-link>
        <p v-if="isLoggedIn"> |</p>
        <a href="#" v-if="isLoggedIn" @click="apiLogout">Logout</a>
    </div>
</template>

<script>
import { mapActions, mapGetters } from 'vuex';

export default {
    name: 'Nav',
    methods: {
        ...mapActions(['logout']),
        apiLogout() {
            const access_token = localStorage.getItem("token");
            if (!!access_token) {
                const header = {
                    'Accept': 'application/json',
                    'Authorization': 'Bearer ' + access_token
                };

                this.$http.get(this.$cfg.API_LOCATION + 'api/auth/logout', {headers: header})
                    .then(response => {
                        console.log(response);
                        this.logout();
                    }).catch(error => {
                        console.log(error); // "oh, no!"
                        this.logout();
                    });
            }
        },
    },
    computed: {
        ...mapGetters(['isLoggedIn']),
    },
};
</script>
