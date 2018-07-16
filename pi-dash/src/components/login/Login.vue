<template>
    <div class="container page">
        <div class="row">
            <div class="col-md-8 col-md-offset-2">
                <h1>Login Form</h1>

                <form @submit.prevent="login(user)">
                    <div class="text-left">
                        <div class="form-group">
                            <label for="email">Email</label>
                            <input type="email" class="form-control" id="email"
                                   placeholder="Your email" v-model="user.email">
                        </div>

                        <div class="form-group">
                            <label for="password">Password</label>
                            <input type="password" class="form-control" id="password"
                                   placeholder="Your password" v-model="user.password">
                        </div>
                    </div>

                    <div class="text-center">
                        <button class="btn btn-primary">Login</button>

                        <br><br>

                        <router-link class="btn btn-default" :to="{name: 'home' }">
                            Home
                        </router-link> |

                        <router-link class="btn btn-default" :to="{name: 'register' }">
                            Register
                        </router-link>
                    </div>
                </form>
            </div>
        </div>
    </div>
</template>

<script>
import {domain} from '@/config'

export default {
    // created () {
    //     this.checkCurrentLogin()
    // },
    // updated () {
    //     this.checkCurrentLogin()
    // },
    data() {
        return {
            user: {
                email: null,
                password: null,
            },
        };
    },
    methods: {
        // checkCurrentLogin() {
        //     if (localStorage.token) {
        //         this.$router.replace(this.$route.query.redirect || '/')
        //     }
        // },
        resetUser() {
            this.user = {
                name: null,
                email: null,
            };
        },
        login(user) {
            this.$http.post( domain + '/api/auth/login', user)
                .then(response => {
                    this.resetUser();
                    // eslint-disable-next-line
                    console.log(response);
                })
                .catch(function (e) {
                    console.log(e);
                });
        },
    },
};
</script>
