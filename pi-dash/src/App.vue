<template>
    <div id="app">
        <div id="nav">
            <router-link to="/">Home</router-link> |
            <router-link to="/about">About</router-link>
        </div>
        <router-view/>
    </div>
</template>

<style>
    #app {
        font-family: 'Avenir', Helvetica, Arial, sans-serif;
        -webkit-font-smoothing: antialiased;
        -moz-osx-font-smoothing: grayscale;
        text-align: center;
        color: #2c3e50;
    }

    #nav {
        padding: 30px;
    }

    #nav a {
        font-weight: bold;
        color: #2c3e50;
    }

    #nav a.router-link-exact-active {
        color: #42b983;
    }
</style>
<script>
export default {
    created() {
        const postData = {
            client_id: 2,
            client_secret: 'ShszeLwsH0LJUuCzKa49YzeO7rvtGe4S8DcOwMFL',
            grant_type: 'password',
            username: 'walz.samuel@gmail.com',
            password: 'secret',
            scope: '*'
        };
        this.$http.post('http://192.168.0.199:8000/oauth/token', postData)
            .then(response => {
            console.log(response);
            const header = {
                'Accept': 'application/json',
                'Authorization': 'Bearer ' + response.body.access_token
            };
            this.$http.get('http://192.168.0.199:8000/api/user', {headers: header})
                .then(response => {
                    console.log(response);
            }).catch(function(e) {
                console.log(e); // "oh, no!"
            });
        }).catch(function(e) {
            console.log(e); // "oh, no!"
        });
    }
}
</script>
