<template>
    <div class="container page">
        <div class="row">
            <div class="col-md-8 col-md-offset-2">
                <h1>Login Form</h1>

                <form @submit.prevent="apiLogin(user)">
                    <div class="text-left">
                        <div class="form-group" :class="{ 'has-error': errors.email.length }">
                            <label for="email">Email</label>
                            <input type="email" class="form-control" id="email" placeholder="Your email"
                                   v-model="user.email">
                            <p class="help-block small text-danger" v-for="error in errors.email" v-bind:key="error">{{ error }}</p>
                        </div>

                        <div class="form-group" :class="{ 'has-error': errors.password.length }">
                        <label for="password">Password</label>
                            <input type="password" class="form-control" id="password" placeholder="Your password"
                                   v-model="user.password">
                            <p class="help-block small text-danger" v-for="error in errors.password" v-bind:key="error">{{ error }}</p>
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
import { mapActions } from 'vuex';

export default {
    data() {
        return {
            user: {
                email: null,
                password: null,
            },
            errors: {
                email: [],
                password: [],
            },
        };
    },
    methods: {
        ...mapActions(['login']),
        resetUser() {
            this.user = {
                name: null,
                email: null,
            };
        },
        apiLogin(user) {
            // eslint-disable-next-line
            this.$http.post(this.$cfg.API_LOCATION + 'api/auth/login', user)
                .then(response => {
                    this.resetUser();
                    /* eslint-disable */
                    this.login(response.body.access_token);
                })
                .catch(error => {
                    let data = error.data.errors;

                    for(let key in this.errors) {
                        if (this.errors.hasOwnProperty(key)) {
                            this.errors[key] = [];

                            let errorMessage = data[key];

                            if(errorMessage) {
                                this.errors[key] = errorMessage;
                            }
                        }
                    }
                });
            /* eslint-enable */
        },
    },
};
</script>
