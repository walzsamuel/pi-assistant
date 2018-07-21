<template>
    <div class="container page">
        <div class="row">
            <div class="col-md-8 col-md-offset-2">
                <h1>Register Form</h1>

                <form @submit.prevent="register(user)">
                    <div class="text-left">
                        <div class="form-group" :class="{ 'has-error': errors.name.length }">
                            <label for="name">Name</label>
                            <input type="text" class="form-control" id="name"
                                   placeholder="Your name" v-model="user.name">
                            <p class="help-block small text-danger" v-for="error in errors.name" v-bind:key="error">{{ error }}</p>
                        </div>

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

                        <div class="form-group" :class="{ 'has-error': errors.password_confirmation.length }">
                            <label for="password_confirmation">Password Confirmation</label>
                            <input type="password" class="form-control" id="password_confirmation"
                                   placeholder="Your password confirmation" v-model="user.password_confirmation">
                            <p class="help-block small text-danger" v-for="error in errors.password_confirmation"
                                v-bind:key="error">{{ error }}</p>
                        </div>
                    </div>

                    <div class="text-center">
                        <button class="btn btn-primary">Register</button>

                        <br><br>

                        <router-link class="btn btn-default" :to="{name: 'home' }">
                            Home
                        </router-link>
                    </div>
                </form>
            </div>
        </div>
    </div>
</template>

<script>

export default {
    data() {
        return {
            user: {
                email: null,
                password: null,
            },
            errors: {
                name: [],
                email: [],
                password: [],
                password_confirmation: [],
            },
        };
    },
    methods: {
        resetUser() {
            this.user = {
                name: null,
                email: null,
                password: null,
                password_confirmation: null,
            };
        },
        register(user) {
        // eslint-disable-next-line
        this.$http.post(this.$cfg.API_LOCATION + 'api/auth/signup', user)
                .then(response => {
                    this.resetUser();
                    // eslint-disable-next-line
                    console.log(response);
                })
            /* eslint-disable */
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
